import os
import sys
import queue
from io import BytesIO, IOBase


def main():
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        s = input()
        q0, q1 = queue.Queue(), queue.Queue()
        belong = [0 for i in range(n)]
        tot = 0
        for i in range(n):
            if s[i] == '0':
                if not q1.empty():
                    f = q1.get()
                    belong[i] = f
                    q0.put(f)
                else:
                    tot += 1
                    belong[i] = tot
                    q0.put(tot)
            else:
                if not q0.empty():
                    f = q0.get()
                    belong[i] = f
                    q1.put(f)
                else:
                    tot += 1
                    belong[i] = tot
                    q1.put(tot)
        print(tot)
        print(*belong)


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
