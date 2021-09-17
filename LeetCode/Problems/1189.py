from collections import defaultdict


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dic = defaultdict(int)
        for ch in text:
            dic[ch] += 1
        return min(dic['b'], dic['a'], dic['l']//2, dic['o']//2, dic['n'])
