dp = [[0, 0, 0] for i in range(105)]
dp[1][0] = dp[1][1] = dp[2][1] = 0
dp[1][2] = dp[2][0] = dp[2][2] = 1
for i in range(3, 101):
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1]
    dp[i][2] = 2**(i - 2) - dp[i - 1][0]
for _ in range(int(input())):
    n = int(input())
    print(dp[n][0] + dp[n][1] + dp[n][2])
