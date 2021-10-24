class Solution:
    def countValidWords(self, sentence: str) -> int:
        s = sentence.split()
        ans = 0

        def valid(token):
            for i in range(10):
                if str(i) in token:
                    return False
            lst = list(token)
            if lst.count('-') > 1 or lst[0] == '-' or lst[-1] == '-':
                return False
            for i in range(len(token)):
                if token[i] == '-' and (not token[i-1].isalpha() or not token[i+1].isalpha()):
                    return False
            nums = lst.count(',') + lst.count('.') + lst.count('!')
            if nums > 1:
                return False
            if nums == 1 and lst[-1] not in ".,!":
                return False
            return True

        for i in s:
            if valid(i):
                ans += 1
        return ans
