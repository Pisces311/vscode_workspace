t = int(input())
while t:
    t -= 1
    n = int(input())
    path = input()
    pos = {(0, 0): 0}
    x, y = 0, 0
    ans = -1, -1
    for i in range(n):
        ch = path[i]
        if ch == 'U':
            y += 1
        elif ch == 'D':
            y -= 1
        elif ch == 'L':
            x -= 1
        else:
            x += 1
        ret = pos.get((x, y))
        if ret is None:
            pos[(x, y)] = i + 1
        else:
            if ans[1] - ans[0] > i - ret or ans[1] == -1:
                ans = ret + 1, i + 1
            pos[(x, y)] = i + 1
    if ans[0] == -1:
        print(-1)
    else:
        print(ans[0], ans[1])
