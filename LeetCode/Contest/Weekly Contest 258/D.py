class Solution:
    def smallestMissingValueSubtree(self, parents: list[int], nums: list[int]) -> list[int]:
        n = len(parents)
        ans = [1] * n
        vis = [False] * 100005
        if 1 not in nums:
            return ans
        g = [[] for _ in range(n)]
        for i in range(n):
            if parents[i] != -1:
                g[parents[i]].append(i)

        def dfs(u):
            if not vis[nums[u]]:
                for v in g[u]:
                    dfs(v)
                vis[nums[u]] = True

        i = nums.index(1)
        miss = 1
        while i >= 0:
            dfs(i)
            while vis[miss]:
                miss += 1
            ans[i] = miss
            i = parents[i]
        return ans
