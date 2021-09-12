class Solution:
    ans = []
    dic = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
           '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}

    def letterCombinations(self, digits: str) -> list[str]:
        if len(digits) == 0:
            return []
        self.ans.clear()
        self.dfs(0, '', digits)
        return self.ans

    def dfs(self, d, cur, digits):
        if d == len(digits):
            self.ans.append(cur)
            return
        for ch in self.dic[digits[d]]:
            self.dfs(d + 1, cur + ch, digits)


sol = Solution()
print(sol.letterCombinations('23'))
