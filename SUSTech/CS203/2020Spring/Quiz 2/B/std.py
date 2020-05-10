import sys


def cal(l):
    return (1 + l) * l // 2


sys.stdin = open('SUSTech/CS203/2020Spring/Quiz 2/B/Input/5.in', 'r')
sys.stdout = open('SUSTech/CS203/2020Spring/Quiz 2/B/Output/5.out', 'w')
for _ in range(int(input())):
    n = int(input())
    zeros = input().split('1')
    ans = 0
    for zero in zeros:
        ans += cal(len(zero))
    print(ans)
