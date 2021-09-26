class Solution:
    def tribonacci(self, n: int) -> int:
        T = [0 for _ in range(n + 5)]
        T[1] = T[2] = 1
        if n > 2:
            for i in range(3, n + 1):
                T[i] = T[i - 1] + T[i - 2] + T[i - 3]
        return T[n]