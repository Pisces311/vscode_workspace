import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


D = int(input())
for case in range(D):
    if case != 0:
        input()
    N, S = map(int, input().split())
    a = [list(map(int, input().split())) for i in range(N)]
    Max = -int(1e20)
    for i in range(N):
        Max = max(Max, a[i][0] - max(0, a[i][1] - S))
    print('Case #%d: %d' % (case + 1, Max))
