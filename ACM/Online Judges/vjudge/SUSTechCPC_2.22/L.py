import sys

sys.stdin = open('little.in', 'r')
sys.stdout = open('little.out', 'w')

n = int(input())
if n & (n - 1) == 0:
    print(-1)
else:
    ans = 0
    axy, ax = [], []
    for i in range(1, 64):
        for j in range(1, 64):
            le, ri = 1, n + 1
            while le <= ri:
                mid = (le + ri) >> 1
                res = mid**i * (mid + 1)**j
                if res < n:
                    le = mid + 1
                elif res > n:
                    ri = mid - 1
                else:
                    ans += 1
                    axy.append((mid, i, j))
                    break
    for i in range(64):
        le, ri = 1, n + 1
        while le <= ri:
            mid = (le + ri) >> 1
            res = mid**i
            if res < n:
                le = mid + 1
            elif res > n:
                ri = mid - 1
            else:
                ans += 1
                ax.append((mid, i))
                break
    print(ans)
    for i in ax:
        print(i[1], end=' ')
        for j in range(i[1]):
            print(i[0], end=' ')
        print()
    for i in axy:
        print(i[1] + i[2], end=' ')
        for j in range(i[1]):
            print(i[0], end=' ')
        for j in range(i[2]):
            print(i[0] + 1, end=' ')
        print()
