class Solution:
    def minimumOperations(self, nums: list[int], start: int, goal: int) -> int:
        def verify(num):
            return 0 <= num <= 1000

        valid = {start}
        num = []
        for i in nums:
            if goal in (start + i, start - i, start ^ i):
                return 1
            elif verify(goal - i) or verify(goal + i) or verify(goal ^ i) or verify(start + i) or verify(start - i) or verify(start ^ i):
                num.append(i)
        for ans in range(1, 1001):
            tmp = set()
            for i in valid:
                for j in num:
                    if verify(i + j):
                        tmp.add(i + j)
                    elif i + j == goal:
                        return ans
                    if verify(i - j):
                        tmp.add(i - j)
                    elif i - j == goal:
                        return ans
                    if verify(i ^ j):
                        tmp.add(i ^ j)
                    elif i ^ j == goal:
                        return ans
            valid |= tmp
            if goal in valid:
                return ans
        return -1
