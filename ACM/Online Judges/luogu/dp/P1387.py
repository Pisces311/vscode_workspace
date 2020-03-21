n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
dp = [[0]*m for i in range(n)]
Max = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == 1:
            if i == 1 or j == 1:
                dp[i][j] = 1
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            Max = max(Max, dp[i][j])
print(Max)
