class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            lst = []
            for i in range(0, len(s), k):
                lst.append(s[i:i+k])
            for i in range(len(lst)):
                lst[i] = sum(map(int, list(lst[i])))
                lst[i] = str(lst[i])
            s = ''.join(lst)
        return s