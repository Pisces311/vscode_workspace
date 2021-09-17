class Solution:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        nums1.sort()
        nums2.sort()
        j = 0
        ans = []
        for i in nums1:
            while j < len(nums2) - 1 and nums2[j] < i:
                j += 1
            if nums2[j] == i:
                ans.append(i)
                j += 1
                if j == len(nums2):
                    break
        return ans


sol = Solution()
print(sol.intersect([3, 1, 2], [1]))
