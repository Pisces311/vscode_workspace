class trash:
    def __init__(self, t, heal, h):
        self.t = t
        self.heal = heal
        self.h = h


D, G = map(int, input().split())
a = []
for i in range(G):
    t, heal, h = map(int, input().split())
    a.append(trash(t, heal, h))
a.sort(key=lambda i: i.t)
dp = [[-1]*105 for i in range(1005)]
dp[-1][0] = 10
res = 10
for i in range(G):
    for j in range(D + 1):
        cost = a[i].t-a[i-1].t if i else a[i].t
        if dp[i-1][j] < cost:
            continue
        if j + a[i].h >= D:
            print(a[i].t)
            exit()
        dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i].heal - cost)
        dp[i][j+a[i].h] = max(dp[i][j+a[i].h], dp[i-1][j] - cost)
    if dp[i][0] > 0:
        res = max(res, dp[i][0]+a[i].t)
print(res)
