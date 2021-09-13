class Solution:
    def maxPalindrome(self, s):
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]+2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][n-1]

    def maxProduct(self, s: str) -> int:
        ans = 1
        for i in range(1, 2**len(s)+1):
            first = ''
            remain = ''
            for j in range(len(s)):
                if i & (2**j):
                    first += s[j]
                else:
                    remain += s[j]
            if first != first[::-1] or not remain:
                continue
            ans = max(ans, len(first) * self.maxPalindrome(remain))
        return ans


sol = Solution()
print(sol.maxProduct('bb'))
