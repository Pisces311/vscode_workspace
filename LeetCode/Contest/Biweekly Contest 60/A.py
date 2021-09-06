class Solution:
    def findMiddleIndex(self, nums: list[int]) -> int:
        tot = sum(nums)
        cur = 0
        for i in range(len(nums)):
            if cur == tot - cur - nums[i]:
                return i
            cur += nums[i]
        return -1


sol = Solution()
print(sol.findMiddleIndex([2, 3, -1, 8, 4]))
