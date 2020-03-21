def solve():
    for i in range(n):
        ret = 0
        for j in range(1, 2 * m, 2):
            ret += data[i][j]
        if ret != 0:
            return False
    for j in range(0, 2 * m, 2):
        ret = 0
        for i in range(n):
            ret += data[i][j]
        if ret != 0:
            return False
    return True


n, m = map(int, input().split())
data = [list(map(int, input().split())) for i in range(n)]
if solve():
    print('Yes')
else:
    print('No')
