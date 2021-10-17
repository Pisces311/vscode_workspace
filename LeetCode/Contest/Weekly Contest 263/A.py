class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        lst = s.split()
        nums = []
        for i in lst:
            try:
                nums.append(int(i))
            except:
                continue
        for i in range(1, len(nums)):
            if nums[i] <= nums[i-1]:
                return False
        return True
