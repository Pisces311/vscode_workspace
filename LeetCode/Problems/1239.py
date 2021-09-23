class Solution:
    def maxLength(self, arr):
        dp = [set()]
        for s in arr:
            if len(set(s)) < len(s):
                continue
            s = set(s)
            for c in dp:
                if not s & c:
                    dp.append(s | c)
        return max(len(s) for s in dp)


sol = Solution()
print(sol.maxLength(["yy", "bkhwmpbiisbldzknpm"]))
