s = input()
n = len(s)
num = [[0]*26 for i in range(n)]
for i in range(n):
    p = ord(s[i]) - ord('a')
    if i != 0:
        for j in range(26):
            num[i][j] = num[i-1][j]
    num[i][p] += 1


def solve(l: int, r: int) -> bool:
    if l == r:
        return True
    elif s[l] != s[r]:
        return True
    else:
        cnt = 0
        for i in range(26):
            if l > 0:
                if num[r][i]-num[l-1][i] > 0:
                    cnt += 1
            else:
                if num[r][i] > 0:
                    cnt += 1
        return True if cnt > 2 else False


q = int(input())
while q > 0:
    l, r = map(int, input().split())
    print('Yes') if solve(l - 1, r - 1) else print('No')
    q -= 1
