n, k = map(int, input().split())
a = list(map(int, input().split()))
dp = [0] * n
tot = 0
for i in range(k):
    tot += a[i]
dp[i] = tot
for i in range(k, n):
    dp[i] = dp[i-1] + a[i] - a[i-k]
Min = float('inf')
ans = -1
for i in range(k-1, n):
    if Min > dp[i]:
        ans = i + 2 - k
        Min = dp[i]
print(ans)
