t = int(input())
while t:
    t -= 1
    a, b, x, y = map(int, input().split())
    area1 = a * y
    area2 = x * b
    area3 = (a - 1 - x) * b
    area4 = a * (b - 1 - y)
    print(max(area1, area2, area3, area4))
