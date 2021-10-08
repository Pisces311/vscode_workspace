class Solution:
    def smallestSubsequence(self, s: str, k: int, letter: str, r: int) -> str:
        cnt = s.count(letter)
        stk = []
        for i, c in enumerate(s):
            # improve the result
            while stk and stk[-1] > c and (len(s) - i + len(stk) > k) and (stk[-1] != letter or cnt > r):
                if letter == stk.pop():
                    r += 1
            if len(stk) < k:
                if c == letter:
                    stk.append(c)
                    r -= 1
                elif k - len(stk) > r:
                    stk.append(c)
            if c == letter:
                cnt -= 1
        return ''.join(stk)
