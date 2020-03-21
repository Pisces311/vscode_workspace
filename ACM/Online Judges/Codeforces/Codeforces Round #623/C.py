t = int(input())
while t:
    t -= 1
    n = int(input())
    vis = [False] * (2 * n)
    ans = [-1] * (2 * n)
    b = list(map(int, input().split()))

    def check():
        global vis
        for i in b:
            if vis[i - 1] is False:
                vis[i - 1] = True
            else:
                return False
        return True

    if check() is False:
        print(-1)
        continue

    def solve():
        global ans, vis
        for i in range(0, 2 * n, 2):
            j = i // 2
            ans[i] = b[j]
            for k in range(b[j] + 1, 2 * n + 1):
                if vis[k - 1] is False:
                    vis[k - 1] = True
                    ans[i + 1] = k
                    break
            if ans[i + 1] == -1:
                return False
        return True

    if solve() is False:
        print(-1)
        continue
    else:
        print(*ans)
