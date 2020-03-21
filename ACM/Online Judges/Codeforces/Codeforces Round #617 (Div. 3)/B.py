t = int(input())
while t > 0:
    t -= 1
    s = int(input())
    ans = 0
    while s >= 10:
        ans += s // 10 * 10
        s = s % 10 + s // 10
    ans += s
    print(ans)
