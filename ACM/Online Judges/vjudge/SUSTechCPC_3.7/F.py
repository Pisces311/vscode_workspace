import sys

sys.stdin = open('foreign.in', 'r')
sys.stdout = open('foreign.out', 'w')


s = input()
n = len(s)
Csum, Wsum, cnt = 0, 0, 0
dp = [0] * n
for i in range(n - 1, -1, -1):
    if s[i] == 'C':
        dp[i] = (cnt + Wsum) / (n - i)
        Csum += n - i
    else:
        dp[i] = (cnt + Csum) / (n - i)
        Wsum += n - i
    cnt += dp[i]
print(dp[0])
