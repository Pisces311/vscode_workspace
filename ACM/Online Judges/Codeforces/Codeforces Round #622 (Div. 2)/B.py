t = int(input())
while t:
    t -= 1
    n, x, y = map(int, input().split())
    x, y = max(x, y), min(x, y)
    _min = min(n, max(x + y - n + 1, 1))
    _max = min(x + y - 1, n)
    print(_min, _max)
