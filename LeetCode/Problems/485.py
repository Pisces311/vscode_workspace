class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        lst = ''.join(map(str, nums)).split('0')
        return len(max(lst))


sol = Solution()
sol.findMaxConsecutiveOnes([1,1,0,1,1,1])
