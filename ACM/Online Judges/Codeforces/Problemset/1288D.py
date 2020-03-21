n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
ans = []


def check(mid: int) -> bool:
    global ans
    dic = {}
    for i in range(n):
        bit = 0
        for j in range(m):
            if a[i][j] >= mid:
                bit += 1
            bit <<= 1
        dic[bit >> 1] = i
    for x, idx in dic.items():
        for y, idy in dic.items():
            if x | y == 2**m-1:
                ans = idx + 1, idy + 1
                return True
    return False


le = 0
ri = int(1e9)
while le <= ri:
    mid = (le + ri) >> 1
    if check(mid):
        le = mid + 1
    else:
        ri = mid - 1
print(ans[0], ans[1])
