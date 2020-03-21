T = int(input())
while T:
    T -= 1
    w, h = map(int, input().split())
    if w == h:
        print('YES')
    else:
        print('NO')
