t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    delta = a.count(0)
    ans = delta
    if sum(a) + delta == 0:
        ans += 1
    print(ans)
