from collections import Counter


class Solution:
    def numberOfGoodSubsets(self, nums: list[int]) -> int:
        mod = 10 ** 9 + 7
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        dp = [0 for _ in range(2 ** 10 + 1)]
        dp[0] = 1
        count = Counter(nums)
        for num in count:
            if num == 1 or num % 4 == 0 or num % 9 == 0 or num == 25:
                continue
            bits = sum(2 ** i for i, p in enumerate(primes) if num % p == 0)
            for i in range(2 ** 10):
                if dp[i] and i & bits == 0:
                    res = i | bits
                    dp[res] += count[num] * dp[i]
                    dp[res] %= mod
        return pow(2, count[1], mod) * (sum(dp) - 1) % mod
