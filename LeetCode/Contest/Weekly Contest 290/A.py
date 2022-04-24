class Solution:
    def intersection(self, nums: list[list[int]]) -> list[int]:
        ans = []
        for num in nums[0]:
            flag = True
            for lst in nums:
                if num not in lst:
                    flag = False
            if flag:
                ans.append(num)
        return sorted(ans)