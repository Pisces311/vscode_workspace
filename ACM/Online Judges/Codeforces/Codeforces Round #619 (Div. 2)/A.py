t = int(input())
while t:
    t -= 1
    a, b, c = input(), input(), input()
    n = len(a)
    flag = True
    for i in range(n):
        if a[i] == c[i] or b[i] == c[i]:
            continue
        else:
            flag = False
    if flag:
        print('YES')
    else:
        print('NO')
