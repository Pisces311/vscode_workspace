t = int(input())
while t:
    t -= 1
    s = input()
    slen = len(s)
    le = 0
    ri = slen - 1
    for i in range(slen):
        le = i
        if s[i] == '1':
            break
    for i in range(slen - 1, -1, -1):
        ri = i
        if s[i] == '1':
            break
    if le >= ri:
        print(0)
    else:
        ans = 0
        for i in range(le, ri + 1):
            if s[i] == '0':
                ans += 1
        print(ans)
