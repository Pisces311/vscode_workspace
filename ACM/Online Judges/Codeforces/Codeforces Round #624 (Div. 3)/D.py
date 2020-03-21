import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


for cas in range(int(input())):
    a, b, c = map(int, input().split())
    ans = 0x3f3f3f3f
    for i in range(1, c + 1):
        for times in range(1, int(2e4 + 5)):
            j = i * times
            if j > int(2e4):
                break
            cur = abs(i - a) + abs(j - b) + min(c % j, j - c % j)
            if cur < ans:
                ans = cur
                A, B = i, j
                C = c - c % j if c % j <= j - c % j else c + j - c % j
            ans = min(ans, cur)
    print(ans)
    print(A, B, C)
