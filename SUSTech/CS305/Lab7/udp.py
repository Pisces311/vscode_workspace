import socket
import random
import time


class UDPsocket(socket.socket):
    def __init__(self, loss_rate=0.1, crpt_rate=0.2,
                 delay_rate=0.1, delay=10):
        super().__init__(socket.AF_INET, socket.SOCK_DGRAM)
        self.loss_rate = loss_rate
        self.crpt_rate = crpt_rate
        self.delay_rate = delay_rate
        self.delay = delay
        self.time = 0.5

    def settimeout(self, value):
        self.time = value
        super().settimeout(self.time)

    def deal_with_random(self, data, addr, bufsize):
        if random.random() < self.delay_rate:
            time.sleep(self.time)
            return None, addr
        if random.random() < self.loss_rate:
            return self.recvfrom(bufsize)
        if random.random() < self.crpt_rate:
            return self._corrupt(data), addr

    def recvfrom(self, bufsize, flags=0):
        data, addr = super().recvfrom(bufsize)
        self.deal_with_random(data, addr, bufsize)
        if data:
            return data, addr

    def _corrupt(self, data):
        raw = list(data)
        for i in range(0, random.randint(0, 3)):
            pos = random.randint(0, len(raw) - 1)
            raw[pos] = random.randint(0, 255)
        return bytes(raw)
