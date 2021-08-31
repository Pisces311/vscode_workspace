class Solution:
    def is_sub(self, s: str, t: str) -> bool:
        index = 0
        for value in s:
            index = t.find(value, index)
            if index == -1:
                return False
            index += 1
        return True

    def check(self, s: str, a) -> bool:
        for i in range(len(s)+1, 11):
            for j in a[i]:
                if self.is_sub(s, j):
                    return False
        return True

    def findLUSlength(self, strs: list[str]) -> int:
        a = [[] for _ in range(11)]
        for s in strs:
            n = len(s)
            a[n].append(s)
        for i in range(10, 0, -1):
            for cur in a[i]:
                if a[i].count(cur) == 1:
                    if self.check(cur, a):
                        return i
        return -1