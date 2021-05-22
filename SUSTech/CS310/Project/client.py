import socket
import struct
import os


def recv_text(s):
    text_len = struct.unpack('i', s.recv(4))[0]
    return s.recv(text_len).decode()


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('10.20.13.130', 9998))

print('Connecting to the server...')

x = input("Press 'p' to record: ")
if x == 'p':
    os.system('ffmpeg -f avfoundation -i :0 -ar 16000 -f wav audio.wav')

file_name = 'audio.wav'
file_bytes = os.path.getsize(file_name)

s.send(struct.pack('i', file_bytes))

with open(file_name, 'rb') as f:
    s.sendall(f.read())

text = recv_text(s)
print('Me:', text)
response = recv_text(s)
print('Bot:', response)

tot = struct.unpack('i', s.recv(4))[0]

recv = 0
msg = b''

with open('response.wav', 'wb') as f:
    while recv < tot:
        if tot - recv > 1024:
            msg = s.recv(1024)
        else:
            msg = s.recv(tot - recv)
        f.write(msg)
        recv += len(msg)

os.system('ffplay -autoexit response.wav')

s.close()
