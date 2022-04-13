class Solution:
    def minimizeResult(self, expression: str) -> str:
        num1, num2 = expression.split('+')
        ans = 10000000000000000
        ret = ""
        for i in range(len(num1)):
            for j in range(1, len(num2) + 1):
                new_ex = num1[:i] + '*(' + num1[i:] + \
                    '+' + num2[:j] + ')*' + num2[j:]
                if new_ex[0] == '*':
                    new_ex = new_ex[1:]
                if new_ex[-1] == '*':
                    new_ex = new_ex[:-1]
                if ans > eval(new_ex):
                    ans = eval(new_ex)
                    ret = new_ex
        return ''.join(ret.split('*'))
