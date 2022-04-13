class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for l in range(1, n + 1):
            for start in range(n - l + 1):
                end = start + l - 1
                dp[start][end] = l
                for k in range(start, end):
                    if s[k] == s[end]:
                        dp[start][end] = min(
                            dp[start][end], dp[start][k] + dp[k + 1][end] - 1)
                    else:
                        dp[start][end] = min(
                            dp[start][end], dp[start][k] + dp[k + 1][end])
        return dp[0][n - 1]
