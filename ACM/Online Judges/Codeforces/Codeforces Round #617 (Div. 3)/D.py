n, a, b, k = map(int, input().split())
h = map(int, input().split())
ans = 0
times = []
for i in h:
    i %= a + b
    if i == 0:
        i = a + b
    if i % a == 0:
        times.append(i // a)
    else:
        times.append(i // a + 1)
times.sort()
for i in times:
    if k >= i - 1:
        k -= i - 1
        ans += 1
print(ans)
