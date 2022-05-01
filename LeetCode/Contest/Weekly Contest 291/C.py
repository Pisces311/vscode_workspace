class Solution:
    def countDistinct(self, nums: list[int], k: int, p: int) -> int:
        n = len(nums)

        def test(a):
            ret = 0
            for i in a:
                if i % p == 0:
                    ret += 1
            return ret <= k

        seen = set()
        for Len in range(1, n + 1):
            for i in range(n - Len + 1):
                cur = tuple(nums[i:i+Len])
                if cur not in seen and test(cur):
                    seen.add(cur)
        return len(seen)
