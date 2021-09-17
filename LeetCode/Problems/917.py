class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        stk = [x for x in s if x.isalpha()]
        return ''.join(stk.pop() if x.isalpha() else x for x in s)
