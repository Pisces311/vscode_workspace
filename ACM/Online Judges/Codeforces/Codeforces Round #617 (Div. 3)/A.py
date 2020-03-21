t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    a = map(int, input().split())
    odd = False
    even = False
    for i in a:
        if i & 1:
            odd = True
        else:
            even = True
    if odd and even:
        print('YES')
    elif odd and n & 1:
        print('YES')
    else:
        print('NO')
