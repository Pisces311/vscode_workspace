class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def isBeautiful(num):
            s = str(num)
            if '0' in s:
                return False
            for i in range(1, 10):
                if s.count(str(i)) not in (0, i):
                    return False
            return True
        for i in range(n + 1, 2000000):
            if isBeautiful(i):
                return i
