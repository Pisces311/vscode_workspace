class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'(': ')', '[': ']', '{': '}'}
        stk = []
        for ch in s:
            if ch in ('(', '[', '{'):
                stk.append(ch)
            else:
                if not stk or dic[stk[-1]] != ch:
                    return False
                else:
                    stk.pop()
        return not stk
