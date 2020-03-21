MAXN = 205

m, n = map(int, input().split())
a = [[0]+list(map(int, input().split()))+[0] for i in range(m)]
dp = [[0] * MAXN for i in range(MAXN)]
for i in range(1, n + 1):
    dp[0][i] = a[0][i]
for i in range(1, m):
    for j in range(1, n + 1):
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])+a[i][j]
print(max(dp[m-1][n//2], dp[m-1][n//2+1], dp[m-1][n//2+2]))
