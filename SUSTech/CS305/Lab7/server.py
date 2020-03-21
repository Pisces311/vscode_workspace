import rdt


server = rdt.MySocket()
server.bind(('127.0.0.1', 8080))
print('The server is now working.')
while True:
    data, client_addr = server.recv()
    if not data:
        break
    data = data.decode()
    print('Data received: ' + str(data))
    new_data = "'" + str(data) + "'" + ' has been processed.'
    server.sendto(new_data.encode(), client_addr)
server.close()
