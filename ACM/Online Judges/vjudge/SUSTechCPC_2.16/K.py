import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


m = int(input())
for case in range(m):
    m -= 1
    n = int(input())
    a = sorted(map(int, input().split()))
    cur, ans = 0, 0
    for i in range(n):
        if cur <= a[i]:
            ans += 1
            cur += a[i]
    print('Case #%d: %d' % (case+1, ans))
