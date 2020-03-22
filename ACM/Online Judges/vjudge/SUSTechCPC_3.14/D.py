n = int(input())
a = list(map(int, input().split()))
suf = [0] * n
suf[n - 1] = a[n - 1]
for i in range(n - 2, -1, -1):
    suf[i] = suf[i + 1] + a[i]
dp = [0] * n
dp[n - 1] = a[n - 1]
for i in range(n - 2, -1, -1):
    dp[i] = max(dp[i + 1], suf[i + 1] - dp[i + 1] + a[i])
print(suf[0] - dp[0], dp[0])
