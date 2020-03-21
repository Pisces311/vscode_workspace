t = int(input())
while t:
    t -= 1
    arr = map(int, input().split())
    a, b, c = sorted(arr, reverse=True)
    ans = 0
    if a:
        ans += 1
        a -= 1
    if b:
        ans += 1
        b -= 1
    if c:
        ans += 1
        c -= 1
    if a and b:
        ans += 1
        a -= 1
        b -= 1
    if a and c:
        ans += 1
        a -= 1
        c -= 1
    if b and c:
        ans += 1
        b -= 1
        c -= 1
    if a and b and c:
        ans += 1
    print(ans)
