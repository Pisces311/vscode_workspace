from bisect import bisect, bisect_left
from math import ceil


class Solution:
    def kthSmallestProduct(self, nums1, nums2, k):
        def check(x):
            total = 0
            for i in nums1:
                if i > 0:
                    total += bisect(nums2, x // i)
                elif i < 0:
                    total += len(nums2) - bisect_left(nums2, ceil(x / i))
                elif i == 0 and x >= 0:
                    total += len(nums2)
            return total
        l, r = -10**10 - 1, 10**10 + 1
        while l + 1 < r:
            mid = (l + r) // 2
            if check(mid) >= k:
                r = mid
            else:
                l = mid
        return l + 1
