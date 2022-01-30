class Solution:
    def findFinalValue(self, nums: list[int], original: int) -> int:
        while original in nums:
            original *= 2
        return original