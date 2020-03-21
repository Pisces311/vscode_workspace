t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    num = []
    for i in range(n):
        if a[i] != -1:
            if i:
                if a[i-1] == -1:
                    num.append(a[i])
            if i != n - 1:
                if a[i+1] == -1:
                    num.append(a[i])
    if num:
        ans = (max(num) + min(num)) // 2
    else:
        ans = 0
    dif = 0
    for i in range(n):
        if a[i] == -1:
            a[i] = ans
        if i:
            dif = max(dif, abs(a[i] - a[i-1]))
    print(dif, ans)
