import asyncio


async def dispatch(reader, writer):
    while True:
        # to obtain data from the server
        data = await reader.readline()
        print(data)
        # to send back the data
        writer.writelines([data])
        if data == b'quit\r\n':
            break
    # wait for socket to send the data
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
    # to close the server
    server.close()
    loop.run_until_complete(server.wait_closed())
    loop.close()
