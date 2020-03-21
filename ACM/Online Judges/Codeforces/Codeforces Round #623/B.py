import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


t = int(input())
while t:
    t -= 1
    a, b, p = map(int, input().split())
    s = input()
    n = len(s)
    change = []
    cur = s[0]
    for i in range(1, n):
        if s[i] == cur:
            continue
        else:
            cur = s[i]
            change.append(i)
    if s[n - 2] == s[n - 1]:
        change.append(n)
    m = len(change)
    cur = s[0]
    if s[0] == 'A':
        tot = a * ((m + 1) // 2) + b * (m - ((m + 1) // 2))
    else:
        tot = b * ((m + 1) // 2) + a * (m - ((m + 1) // 2))
    ans = 0
    if p >= tot:
        print(1)
        continue
    cur = s[0]
    for i in range(1, n):
        if s[i] != cur:
            tot -= a if cur == 'A' else b
            cur = s[i]
            if tot <= p:
                print(i + 1)
                break
    else:
        print(n)
