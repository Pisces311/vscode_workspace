n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
pos, neg = 0, 0
for i in range(n):
    if a[i] == 1 and b[i] == 0:
        pos += 1
    elif a[i] == 0 and b[i] == 1:
        neg += 1
if pos == 0:
    print(-1)
else:
    ret = neg // pos
    if ret * pos <= neg:
        ret += 1
    print(ret)
