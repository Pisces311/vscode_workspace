class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        ans = [[], []]
        for i in nums1:
            if i not in nums2 and i not in ans[0]:
                ans[0].append(i)
        for i in nums2:
            if i not in nums1 and i not in ans[1]:
                ans[1].append(i)
        return ans