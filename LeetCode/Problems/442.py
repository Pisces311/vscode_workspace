from collections import defaultdict

class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        dic = defaultdict(int)
        for i in nums:
            dic[i] += 1
        ret = []
        for i in range(1, len(nums) + 1):
            if dic[i] > 1:
                ret.append(i)
        return ret
