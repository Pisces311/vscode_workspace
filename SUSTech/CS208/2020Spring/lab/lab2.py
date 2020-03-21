MOD = 998244353


class number:
    def __init__(self, num: str, length: int, pre: list):
        self.num = num
        self.length = length
        self.pre = pre


input()
a, cnt = [], [0] * 11
data = input().split()
for num in data:
    pre = [0] * 11
    cnt[len(num)] += 1
    for i in range(1, len(num) + 1):
        pre[i] = int(num[i - 1]) + (0 if i == 1 else pre[i - 1] * 10)
    a.append(number(num, len(num), pre))
tot = [0] * 11
for i in range(10, 0, -1):
    tot[i] = cnt[i] + (0 if i == 10 else tot[i + 1])
ans = 0
for i in a:
    for j in range(1, i.length + 1):
        ans = (ans + i.pre[i.length - j] * 10**(2 * j) * cnt[j] * 2) % MOD
        ans = (ans + int(i.num[i.length - j]) *
               11 * 10**(2 * (j - 1)) * tot[j]) % MOD
print(ans)
