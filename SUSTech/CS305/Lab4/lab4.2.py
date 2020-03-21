import asyncio
import os
import mimetypes
from urllib import parse

# normal response
ok200 = [b'HTTP/1.0 200 OK\r\n',
         b'Connection: close\r\n'
         b'Content-Type:text/html; charset=utf-8\r\n',
         b'\r\n']
# response when file does not exist
err404 = [b'HTTP/1.0 404 Not Found\r\n',
          b'Connection: close\r\n'
          b'Content-Type:text/html; charset=utf-8\r\n',
          b'\r\n',
          b'<html><body>404 Not Found<body></html>\r\n',
          b'\r\n']
# response when the request is other than get/head
err405 = [b'HTTP/1.0 405 Method Not Allowed\r\n',
          b'Connection: close\r\n'
          b'Content-Type:text/html; charset=utf-8\r\n',
          b'\r\n',
          b'<html><body>405 Method Not Allowed<body></html>\r\n',
          b'\r\n']


def breakCondition(message, data):
    if message == [''] or data == b'\r\n':
        return True
    else:
        return False


def solveFile(lst, path):
    lst.append(b'HTTP/1.0 200 OK\r\n')
    lst.append(b'Connection: close\r\n')
    # return the size of the file
    size = os.path.getsize(path)
    lst.append(b'Content-Length: %s\r\n' %
               (str(size).encode('utf-8')))
    # return the type of the file
    filetype = mimetypes.guess_type(path)[0]
    # download if the browser dose not open it
    if filetype is None:
        filetype = 'application/octet-stream'
    lst.append(b'Content-Type: %s; charset=utf-8\r\n' %
               (filetype.encode('utf-8')))
    lst.append(b'\r\n')
    print(lst)


def solveFolder(lst, path):
    lst.append(b'<html>')
    lst.append(b'<head><title>Index of %s</title></head>' %
               (path.encode('utf-8')))
    lst.append(b'<body bgcolor="white">')
    lst.append(b'<h1>Index of %s</h1><hr>' % (path.encode('utf-8')))
    lst.append(b'<ul>')
    for i in os.listdir(path):
        if os.path.isdir(path + i + '/'):
            i = i + '/'
        lst.append(b'<li><a href="%s"> %s </a></li>' %
                   (i.encode('utf-8'), i.encode('utf-8')))
    lst.append(b'</ul>')
    lst.append(b'</body>')
    lst.append(b'</html>')


async def dispatch(reader, writer):
    # request type & content
    method, path = ['', '']
    while True:
        data = await reader.readline()
        message = data.decode().split(' ')
        print('message:%s' % message)
        # record request message
        if path == '' and len(message) >= 2:
            method, path = [message[0], message[1]]
        if breakCondition(message, data):
            break
    print('method:%s' % method)
    print('path:%s' % path)
    # package to be ignored
    if path != 'favicon.ico':
        # if request is not get/head, return 405
        if method != 'GET' and method != 'HEAD':
            writer.writelines(err405)
        else:
            # add a dot before the path
            path = '.' + path
            # decode url
            try:
                path = parse.unquote(path, errors='surrogatepass')
            except UnicodeDecodeError:
                path = parse.unquote(path)
            # head
            lst = []
            # judge if it's a file
            if os.path.isfile(path):
                solveFile(lst, path)
                writer.writelines(lst)
                file = open(path, 'rb')
                if method == 'GET':
                    file_content = file.readlines()
                    writer.writelines(file_content)
            # judge if it's a folder
            elif os.path.isdir(path):
                if method == 'HEAD':
                    writer.writelines(ok200)
                elif method == 'GET':
                    writer.writelines(ok200)
                    solveFolder(lst, path)
                    writer.writelines(lst)
            else:
                # return 404 when the request is not found
                writer.writelines(err404)
    await writer.drain()
    writer.close()


if __name__ == '__main__':
    # to create a new event loop
    loop = asyncio.get_event_loop()
    # to start a new cooperation
    coro = asyncio.start_server(dispatch, '127.0.0.1', 8080, loop=loop)
    # to start up the event loop
    server = loop.run_until_complete(coro)
    # to serve requests until the process is interrupted
    print('Serving on {}'.format(server.sockets[0].getsockname()))
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass
    # close the server
    server.close()
    # keep waiting until data flow is closed
    loop.run_until_complete(server.wait_closed())
    loop.close()
