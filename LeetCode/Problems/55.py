class Solution:
    def canJump(self, nums: list[int]) -> bool:
        r = 0
        for i, l in enumerate(nums):
            if i > r:
                return False
            r = max(r, i + l)
        return True
