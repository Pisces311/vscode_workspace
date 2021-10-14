class Solution:
    def minOperations(self, grid: list[list[int]], x: int) -> int:
        nums = []
        for i in grid:
            nums.extend(i)
        for i in range(len(nums)):
            if nums[i] % x != nums[0] % x:
                return -1
        nums.sort()

        def cal(tgt):
            ret = 0
            for i in nums:
                ret += abs(i - tgt) // x
            return ret

        return min(cal(nums[len(nums)//2-1]), cal(nums[len(nums)//2]))
