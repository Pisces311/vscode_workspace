import sys

sys.stdin = open('auxiliary.in', 'r')
sys.stdout = open('auxiliary.out', 'w')

n = int(input())
ans = 0
ans += n // 3 * 7
n %= 3
if n == 1:
    ans += 4 - 7
elif n == 2:
    ans += 1
print(ans)
