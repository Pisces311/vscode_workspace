class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        s = '#' + s
        t = '#' + t
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 1
        for j in range(1, m + 1):
            for i in range(1, n + 1):
                dp[i][j] = dp[i-1][j]
                if s[i] == t[j]:
                    dp[i][j] += dp[i-1][j-1]
        return dp[n][m]
