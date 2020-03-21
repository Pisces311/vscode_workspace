T, m = map(int, input().split())
item = [list(map(int, input().split())) for i in range(m)]
dp = [0]*(T+1)
for i in range(m):
    for j in range(item[i][0], T + 1):
        dp[j] = max(dp[j], dp[j-item[i][0]]+item[i][1])
print(max(dp))
