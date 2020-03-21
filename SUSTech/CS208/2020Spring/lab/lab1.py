import os
import sys
import queue
from io import BytesIO, IOBase


def main():
    n = int(input())
    order = [''] * n
    x, y = {}, {}
    xprf = [[-1] * n for i in range(n)]
    yprf = [[-1] * n for i in range(n)]
    inv = [[-1] * n for i in range(n)]
    xmatch, ymatch = [-1] * n, [-1] * n
    cnt = [0] * n
    for i in range(n):
        data = input().split()
        order[i] = data[0]
        x[data[0]] = i
        x[i] = data[0]
        for j in range(n):
            if i == 0:
                y[data[j + 1]] = j
                y[j] = data[j + 1]
                xprf[i][j] = j
            else:
                xprf[i][j] = y[data[j + 1]]
    for i in range(n):
        data = input().split()
        u = y[data[0]]
        for j in range(n):
            v = x[data[j + 1]]
            yprf[u][j] = v
            inv[u][v] = j
    q = queue.Queue()
    for i in range(n):
        q.put(i)
    while not q.empty():
        f = q.get()
        while xmatch[f] == -1:
            tar = xprf[f][cnt[f]]
            if ymatch[tar] == -1:
                xmatch[f], ymatch[tar] = tar, f
            elif inv[tar][ymatch[tar]] > inv[tar][f]:
                q.put(ymatch[tar])
                xmatch[ymatch[tar]] = -1
                xmatch[f], ymatch[tar] = tar, f
            cnt[f] += 1
    for i in range(n):
        print(order[i], y[xmatch[i]])


# region fastio
BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


def input(): return sys.stdin.readline().rstrip("\r\n")

# endregion


if __name__ == "__main__":
    main()
