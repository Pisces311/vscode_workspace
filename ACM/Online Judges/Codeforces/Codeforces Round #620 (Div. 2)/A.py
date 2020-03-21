t = int(input())
while t:
    t -= 1
    x, y, a, b = map(int, input().split())
    dis = y - x
    if dis % (a + b) == 0:
        print(dis // (a + b))
    else:
        print(-1)
