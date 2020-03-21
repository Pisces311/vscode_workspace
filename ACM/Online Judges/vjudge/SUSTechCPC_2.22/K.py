import sys

sys.stdin = open('kotlin.in', 'r')
sys.stdout = open('kotlin.out', 'w')


def print_ans(x: int, y: int):
    ans = [['.'] * w for i in range(h)]
    for i in range(1, 2 * x, 2):
        for j in range(w):
            ans[i][j] = '#'
    for j in range(1, 2 * y, 2):
        for i in range(h):
            ans[i][j] = '#'
    for i in range(h):
        for j in range(w):
            print(ans[i][j], end='')
        print()


h, w, n = map(int, input().split())
row, col = (h - 1) // 2, (w - 1) // 2
for i in range(row + 1):
    for j in range(col + 1):
        if (i + 1) * (j + 1) == n:
            print_ans(i, j)
            exit()
print('Impossible')
