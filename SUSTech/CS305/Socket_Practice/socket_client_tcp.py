import socket


client = socket.socket()
ip_port = ("127.0.0.1", 8080)
client.connect(ip_port)
while True:
    data = client.recv(1024)
    print(data.decode())
    msg_input = input("Please input msg: ")
    client.send(msg_input.encode())
    if msg_input == "exit":
        break
    data = client.recv(1024)
    print(data.decode())
