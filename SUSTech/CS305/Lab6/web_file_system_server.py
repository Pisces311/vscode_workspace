# encoding:utf-8
import asyncio
import os
import mimetypes
from urllib import parse


class Server():
    response = {
        #  file not exists
        404: [b'HTTP/1.0 404 Not Found\r\n',
              b'Connection: close\r\n',
              b'Content-Type:text/html; charset=utf-8\r\n',
              b'\r\n',
              b'<html><body>404 Not Found<body></html>\r\n',
              b'\r\n'],
        # request beyond GET/HEAD
        405: [b'HTTP/1.0 405 Method Not Allowed\r\n',
              b'Connection: close\r\n',
              b'Content-Type:text/html; charset=utf-8\r\n',
              b'\r\n',
              b'<html><body>405 Method Not Allowed<body></html>\r\n',
              b'\r\n'],
        # Range Header
        406: [b'HTTP/1.0 416 Requested Range Not Satisfiable\r\n',
              b'Connection: close\r\n',
              b'Content-Type:text/html; charset=utf-8\r\n',
              b'\r\n',
              b'<html><body>%b<body></html>\r\n' \
              % b'416 Requested Range Not Satisfiable',
              b'\r\n']
    }

    # split the cookie
    def __get_cookie(self, cookies):
        for i in cookies:
            cookie = i.strip('\r\n').split(' ')
            for j in cookie:
                if 'loc=' in j:
                    return j.strip(';').strip('path=/')

    def __get_description(self, lst, path, length):
        mime = 'application/octet-stream' if mimetypes.guess_type(
            path)[0] is None else mimetypes.guess_type(path)[0]
        lst.append('Content-Type: {}\r\n'.format(mime).encode('utf-8'))
        lst.append(
            'Content-Length: {}\r\n'.format(length).encode('utf-8'))
        lst.append(b'Connection: close\r\n')
        lst.append(b'\r\n')

    def __solve_folder(self, lst, path):
        file_list = os.listdir(path)
        lst.append(b'<html>')
        lst.append(b'<head><title>Index of %s</title></head>' %
                   (path.encode('utf-8')))
        lst.append(b'<body bgcolor="white">')
        lst.append(b'<h1>Index of %s</h1><hr>' %
                   (path.encode('utf-8')))
        lst.append(b'<ul>')
        if path != './':
            lst.append(b'<li><a href=".."> ../ </a></li>')
        for i in file_list:
            if os.path.isdir(path + i + '/'):
                i = i + '/'
            lst.append(b'<li><a href="%s"> %s </a></li>' %
                       (i.encode('utf-8'), i.encode('utf-8')))
        lst.append(b'</ul>')
        lst.append(b'</body>')
        lst.append(b'</html>')

    async def __dispatch(self, reader, writer):
        header = {}
        while True:
            data = await reader.readline()
            if data in (b'\r\n', b''):
                break
            msg = data.decode().split(' ')
            if msg[0] in ('GET', 'HEAD', 'POST'):
                header['METHOD'] = msg[0]
                header['PATH'] = msg[1]
            if msg[0] == 'Range:':
                header['RANGE'] = msg[1]
            if msg[0] == 'Cookie:':
                header['COOKIE'] = msg
            if msg[0] == 'Referer:':
                header['REFERER'] = msg[1]
            if msg[0] == 'Host:':
                header['HOST'] = msg[1]
        print('header: %s' % header)
        # Handle the header
        r_head, r = [], []
        if 'METHOD' not in header:
            writer.writelines(Server.response[405])
            await writer.drain()
            writer.close()
            return
        cookie = ''
        if 'COOKIE' in header:
            cookie = self.__get_cookie(header['COOKIE'])
            print('cookie: %s' % cookie)
        if 'RANGE' in header:
            r_head.append(b'HTTP/1.0 206 Partial Content\r\n')
        else:
            if header['PATH'] == '/' and 'REFERER' not in header and \
                'COOKIE' in header and 'loc=' in cookie and \
                    cookie != 'loc=/':
                r_head.append(b'HTTP/1.0 302 Found\r\n')
            else:
                r_head.append(b'HTTP/1.0 200 OK\r\n')
        if header['PATH'] == '/' and 'REFERER' not in header and  \
                'COOKIE' in header and 'loc=' in cookie and cookie != 'loc=/':
            cookie_loc = cookie[4:]
            header['HOST'] = header['HOST'].strip('\r\n')
            url = 'http://' + header['HOST'] + cookie_loc
            print('url: %s' % url)
            r_head.append('Location: {}\r\n\r\n'.format(url).encode('utf-8'))
            r_head.append('Cache-control: private; max-age={}\r\n\r\n'
                          .format(86400).encode('utf-8'))
            writer.writelines(r_head)
            await writer.drain()
            writer.close()
            return

        path = './' + header['PATH']
        # decode url
        try:
            path = parse.unquote(path, errors='surrogatepass')
        except UnicodeDecodeError:
            path = parse.unquote(path)
        # judge whether it is a file
        if os.path.isfile(path):
            size = int(os.path.getsize(path))
            start_ind, end_ind = 0, size - 1
            length = size
            if 'RANGE' in header:
                start_ind, end_ind = header['RANGE'].strip(
                    'bytes=').split('-')
                if not start_ind and not end_ind or end_ind == '\r\n':
                    start_ind, end_ind = 0, size - 1
                elif not end_ind or end_ind == '\r\n':
                    start_ind, end_ind = int(start_ind), size - 1
                elif not start_ind:
                    end_ind = int(end_ind)
                    start_ind = size - end_ind
                    end_ind = size - 1
                start_ind = int(start_ind)
                end_ind = int(end_ind)
                length = end_ind - start_ind + 1
                if start_ind < 0 or end_ind >= size or start_ind > end_ind:
                    writer.writelines(Server.response[416])
                    await writer.drain()
                    writer.close()
                    return
                r_head.append('Content-Range: bytes {}-{}/{}\r\n'
                              .format(start_ind, end_ind, size)
                              .encode('utf-8'))
            self.__get_description(r_head, path, length)
            writer.writelines(r_head)
            if header['METHOD'] == 'GET':
                file = open(path, 'rb')
                file.seek(start_ind)
                writer.write(file.read(length))
                file.close()
        # judge whether it is a folder
        elif os.path.isdir(path):
            r_head.append(b'Connection: close\r\n')
            r_head.append(b'Content-Type:text/html; charset=utf-8\r\n')
            r_head.append('Set-Cookie: loc={};path=/\r\n'
                          .format(header['PATH']).encode('utf-8'))
            r_head.append(b'\r\n')
            if header['METHOD'] == 'HEAD':
                writer.writelines(r_head)
            elif header['METHOD'] == 'GET':
                writer.writelines(r_head)
                # get the names of files inside the folder
                self.__solve_folder(r, path)
                writer.writelines(r)
        else:
            writer.writelines(Server.response[404])
        await writer.drain()
        writer.close()

    def work(self):
        # to create a event loop
        loop = asyncio.get_event_loop()
        coro = asyncio.start_server(
            self.__dispatch, '127.0.0.1', 8080, loop=loop)
        server = loop.run_until_complete(coro)
        # press Ctrl + C to stop
        print('Serving on {}'.format(server.sockets[0].getsockname()))
        try:
            loop.run_forever()
        except KeyboardInterrupt:
            # Close the server
            server.close()
            loop.run_until_complete(server.wait_closed())
            loop.close()


server = Server()
server.work()
