import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


q = int(input())
while q:
    q -= 1
    n, m = map(int, input().split())
    cus = [list(map(int, input().split())) for i in range(n)]

    def check():
        cur, maxtemp, mintemp = 0, m, m
        for i in range(n):
            delta = cus[i][0] - cur
            cur = cus[i][0]
            maxtemp += delta
            mintemp -= delta
            maxtemp = min(maxtemp, cus[i][2])
            mintemp = max(mintemp, cus[i][1])
            if maxtemp < mintemp:
                return False
        return True

    if check():
        print('YES')
    else:
        print('NO')
