class Solution:
    def kthPalindrome(self, queries: list[int], intLength: int) -> list[int]:
        ans = []
        for query in queries:
            base = 10**((intLength+1) // 2 - 1)
            num = base + query - 1
            if intLength % 2 == 0:
                cur = str(num)+str(num)[::-1]
            else:
                cur = str(num)+str(num)[:-1][::-1]
            if len(cur) == intLength:
                ans.append(cur)
            else:
                ans.append(-1)
        return ans
