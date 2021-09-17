from math import modf

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        ret = dividend / divisor
        ans = int(modf(ret)[1])
        return min(ans, 2**31-1)