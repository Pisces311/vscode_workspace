class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        a = preorder.split(',')
        stk = []
        for i in a:
            stk.append(i)
            while len(stk) > 2 and stk[-1] == '#' and stk[-2] == '#':
                stk.pop()
                stk.pop()
                if stk[-1] == '#':
                    return False
                stk.pop()
                stk.append('#')
        if len(stk) == 1 and stk[0] == '#':
            return True
        return False