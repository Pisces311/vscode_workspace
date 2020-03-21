n = int(input())
m = [0] + list(map(int, input().split())) + [0]
stk = [0] * (n + 2)
le, ri = [0] * (n + 2), [0] * (n + 2)
pos = [0] * (n + 2)
ans = [0] * (n + 2)
top = 0
for i in range(1, n + 1):
    while top and stk[top] > m[i]:
        top -= 1
    le[i] = le[pos[top]] + (i - pos[top]) * m[i]
    top += 1
    stk[top], pos[top] = m[i], i
top = 0
pos[0] = n + 1
for i in range(n, 0, -1):
    while top and stk[top] > m[i]:
        top -= 1
    ri[i] = ri[pos[top]] + (pos[top] - i) * m[i]
    top += 1
    stk[top], pos[top] = m[i], i
_max, idx = 0, 1
for i in range(1, n + 1):
    if le[i] + ri[i] - m[i] > _max:
        _max = le[i] + ri[i] - m[i]
        idx = i
ans[idx] = m[idx]
for j in range(idx - 1, 0, -1):
    ans[j] = min(m[j], ans[j + 1])
for j in range(idx + 1, n + 1):
    ans[j] = min(m[j], ans[j - 1])
print(*ans[1:-1])
