pow2 = [0] * 85
pow2[1] = 2
for i in range(2, 81):
    pow2[i] = pow2[i - 1] * 2
n, m = map(int, input().split())
ans = 0
for i in range(n):
    a = [0] + list(map(int, input().split())) + [0]
    dp = [[0] * 85 for i in range(85)]
    for j in range(1, m + 1):
        for k in range(m, j - 1, -1):
            dp[j][k] = max(dp[j][k], dp[j - 1][k] + a[j - 1] * pow2[m-k+j-1])
            dp[j][k] = max(dp[j][k], dp[j][k + 1] + a[k + 1] * pow2[m-k+j-1])
    Max = 0
    for j in range(1, m + 1):
        Max = max(Max, dp[j][j] + a[j] * pow2[m])
    ans += Max
print(ans)
