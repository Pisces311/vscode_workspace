import socket
from dnslib import DNSRecord
import time


def get_min_ttl(lst: list) -> int:
    mn = 600
    for i in lst:
        mn = min(mn, i.ttl)
    return mn


def set_min_ttl(lst: list, mn: int):
    for i in lst:
        i.ttl = mn


def query(query_data, Server, port_num):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.sendto(query_data, (Server, 53))
    response, server_address = client_socket.recvfrom(4096)
    return response


port_num = 12000
cache, ddl = [{}, {}]
Server = '114.114.114.114'
socket_server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
socket_server.bind(('', port_num))
# to start the program
print("DNS server is now working! You can start digging now.")
print("-----------------------------------------------------------")


while True:
    message, clientAddress = socket_server.recvfrom(4096)
    print("Digging request received.")
    print("Processing...")
    request = DNSRecord.parse(message)
    question = request.questions
    rid = request.header.id
    if cache.get(repr(question)):
        reply = cache.get(repr(question))
        print("hit")
        if time.time() > ddl[repr(question)]:
            print("Time limit exceeded!")
            reply = DNSRecord.parse(query(message, Server, port_num))
            # to set the minimum time to live
            set_min_ttl(reply.rr, get_min_ttl(reply.rr))
            cache[repr(question)] = DNSRecord.pack(reply)
            ddl[repr(question)] = time.time() + reply.a.ttl
        else:
            reply = DNSRecord.parse(reply)
            reply.header.id = rid
            for i in reply.rr:
                i.ttl = int(ddl[repr(question)]-time.time())
            reply = DNSRecord.pack(reply)
    else:
        reply = DNSRecord.parse(query(message, Server, port_num))
        # to set the minimum time to live
        set_min_ttl(reply.rr, get_min_ttl(reply.rr))
        cache[repr(question)] = DNSRecord.pack(reply)
        ddl[repr(question)] = time.time() + reply.a.ttl
    socket_server.sendto(DNSRecord.pack(reply), clientAddress)
    print("Response messages has been successfully sent.")
