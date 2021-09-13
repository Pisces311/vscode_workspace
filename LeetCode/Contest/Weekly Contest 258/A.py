class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        p = word.find(ch)
        if p != -1:
            word = word[p::-1]+word[p+1:]
        return word
