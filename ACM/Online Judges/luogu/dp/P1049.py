V = int(input())
n = int(input())
dp = [0] * (V + 1)
for i in range(n):
    c = int(input())
    for j in range(V, c - 1, -1):
        dp[j] = max(dp[j], dp[j - c] + c)
print(V-dp[V])
