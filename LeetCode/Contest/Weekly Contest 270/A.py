class Solution:
    def findEvenNumbers(self, digits: list[int]) -> list[int]:
        ans = set()
        n = len(digits)
        for i in range(n):
            if digits[i]:
                for j in range(n):
                    if i != j:
                        for k in range(n):
                            if j != k and i != k:
                                num = digits[i] * 100 + digits[j] * 10 + digits[k]
                                if num % 2 == 0:
                                    ans.add(num)
        return sorted(list(ans))