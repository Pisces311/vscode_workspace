class Solution:
    def addOperators(self, num: str, target: int) -> list[str]:
        ans = []

        def dfs(cur: str, d: int):
            if d == len(num):
                if eval(cur) == target:
                    ans.append(cur)
                return
            ops = ('+', '-', '*')
            for i in ops:
                dfs(cur + i + num[d], d + 1)
            if cur[-1] != '0' or (cur[-1] == '0' and len(cur) > 1 and cur[-2].isdigit()):
                dfs(cur + num[d], d + 1)

        dfs(num[0], 1)

        return ans


sol = Solution()
print(sol.addOperators('123', 6))
