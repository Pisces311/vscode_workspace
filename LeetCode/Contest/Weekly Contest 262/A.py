from collections import Counter


class Solution:
    def twoOutOfThree(self, nums1: list[int], nums2: list[int], nums3: list[int]) -> list[int]:
        a = []
        a.extend(set(nums1))
        a.extend(set(nums2))
        a.extend(set(nums3))
        counter = Counter(a)
        return [i for i, j in counter.items() if j >= 2]
