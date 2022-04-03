class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        curh = int(current[:2])
        curm = int(current[-2:])
        corh = int(correct[:2])
        corm = int(correct[-2:])
        if corm < curm:
            corh -= 1
            corm += 60
        ans = corh - curh
        while corm - curm >= 15:
            curm += 15
            ans += 1
        while corm - curm >= 5:
            curm += 5
            ans += 1
        ans += corm - curm
        return ans
