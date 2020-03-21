import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


while True:
    data = list(map(int, input().split()))
    T = data[0]
    if T == 0:
        break
    n = data[1]
    a = data[2:]
    dp = [0] * (T + 1)
    path = [[0] * 1005 for i in range(n)]
    for i in range(n-1, -1, -1):
        for j in range(T, a[i] - 1, -1):
            if dp[j-a[i]] + a[i] >= dp[j]:
                dp[j] = dp[j-a[i]] + a[i]
                path[i][j] = 1
    vol = T
    for i in range(n):
        if path[i][vol] == 1:
            print(a[i], end=' ')
            vol -= a[i]
    print(dp[T])
