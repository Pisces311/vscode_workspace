class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if not s or s[0] not in ['-', '+'] and not s[0].isdigit():
            return 0
        pos = True
        if s[0] == '-':
            pos = False
            s = s[1:]
        elif s[0] == '+':
            s = s[1:]
        ret = ""
        i = 0
        while i < len(s) and s[i].isdigit():
            ret += s[i]
            i += 1
        if not ret:
            return 0
        elif pos:
            ret = int(ret)
        else:
            ret = -int(ret)
        ret = min(ret, 2 ** 31 - 1)
        ret = max(ret, -2 ** 31)
        return ret


sol = Solution()
sol.myAtoi('42')
