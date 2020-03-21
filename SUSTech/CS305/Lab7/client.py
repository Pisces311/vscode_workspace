import time
import rdt

client = rdt.MySocket()
start_time = time.time()
client.sendto('This is a simple message.'.encode(), ('127.0.0.1', 8080))
data, server_addr = client.recv()
data = data.decode()
print('Received: ', data)
print('Round trip time:', time.time() - start_time)
print('-------------------------------------------------------------')
print('The connection is over, the program will be closed in 5s.')
time.sleep(5)
