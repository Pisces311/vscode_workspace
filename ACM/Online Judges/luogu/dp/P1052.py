L = int(input())
S, T, M = map(int, input().split())
stone = sorted(map(int, input().split()))+[0]
if S == T:
    ans = 0
    for i in range(M):
        if stone[i] % S == 0:
            ans += 1
    print(ans)
    exit()
MAX_LEN = 90 * 105
dp = [0x3f3f3f3f] * MAX_LEN
a = [0] * MAX_LEN
path = [0] * MAX_LEN
for i in range(M):
    dis = min(stone[i] - stone[i-1], S*T)
    a[i] = a[i-1]+dis
    path[a[i]] = 1
L = a[M-1]+S*T
dp[0] = 0
for i in range(1, L + 1):
    for j in range(S, T + 1):
        if i - j >= 0:
            dp[i] = min(dp[i], dp[i-j] + path[i])
print(dp[L])
