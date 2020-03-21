n, k = map(int, input().split())
ans = 0x3f3f3f3f
if k >= n:
    print(1)
    exit()
for i in range(1, k):
    rst, b = k - i, i
    day = 1
    while True:
        b += min(b, (n - b) // 2)
        if n - b <= rst:
            break
        day += 1
    ans = min(day + 1, ans)
print(ans)
