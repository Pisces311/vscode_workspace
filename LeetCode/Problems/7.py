class Solution:
    def reverse(self, x: int) -> int:
        sx = str(x)
        if sx[0] == '-':
            ret = int('-' + sx[:0:-1])
        else:
            ret = int(sx[::-1])
        if ret > 2 ** 31 - 1 or ret < -2 ** 31:
            return 0
        return ret