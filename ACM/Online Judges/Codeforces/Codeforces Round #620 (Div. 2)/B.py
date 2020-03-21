import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


n, m = map(int, input().split())
strs = [input() for i in range(n)]
used = [False for i in range(n)]


def palindrome(x: int, y: int) -> bool:
    if strs[x] == strs[y][::-1]:
        return True
    else:
        return False


def self_palindrome(x: int) -> bool:
    if strs[x] == strs[x][::-1]:
        return True
    else:
        return False


ans = []
self_pa = []
for i in range(n):
    for j in range(i + 1, n):
        if not used[i] and not used[j]:
            if palindrome(i, j):
                ans.append(i)
                ans.append(j)
                used[i], used[j] = True, True
for i in range(n):
    if not used[i] and self_palindrome(i):
        self_pa.append(i)
        break
up = len(ans)
print(up*m+len(self_pa)*m)
for i in range(0, up, 2):
    print(strs[ans[i]], end='')
for i in self_pa:
    print(strs[i], end='')
for i in range(up-1, -1, -2):
    print(strs[ans[i]], end='')
print()
