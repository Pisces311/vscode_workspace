class Solution:
    def scoreOfStudents(self, s: str, answers: list[int]) -> int:
        correct = eval(s)
        dp = [[set() for _ in range(len(s) + 1)] for _ in range(len(s) + 1)]

        def dfs(i, j):
            if i + 1 == j:
                ret = set()
                ret.add(int(s[i]))
                return ret
            if len(dp[i][j]):
                return dp[i][j]
            for op in range(i + 1, j, 2):
                set1 = dfs(i, op)
                set2 = dfs(op + 1, j)
                for lv in set1:
                    for rv in set2:
                        num = lv + rv if s[op] == '+' else lv * rv
                        if num <= 1000:
                            dp[i][j].add(num)
            return dp[i][j]

        possible = dfs(0, len(s))
        ans = answers.count(correct) * 5
        for i in possible:
            if i != correct:
                ans += answers.count(i) * 2
        return ans
