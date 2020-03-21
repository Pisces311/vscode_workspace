n = int(input())
m = list(map(int, input().split()))
ans, idx = 0, -1
for i in range(n):
    a = [0] * n
    a[i] = m[i]
    for j in range(i - 1, -1, -1):
        a[j] = min(m[j], a[j + 1])
    for j in range(i + 1, n):
        a[j] = min(m[j], a[j - 1])
    tot = sum(a)
    if tot > ans:
        ans = tot
        idx = i
a = [0] * n
a[idx] = m[idx]
for j in range(idx - 1, -1, -1):
    a[j] = min(m[j], a[j + 1])
for j in range(idx + 1, n):
    a[j] = min(m[j], a[j - 1])
print(*a)
