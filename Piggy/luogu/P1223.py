class people:
    def __init__(self, idx, t):
        self.idx = idx
        self.t = t


n = int(input())
T = list(map(int, input().split()))
a = []
for i in range(n):
    a.append(people(i + 1, T[i]))
a.sort(key=lambda x: x.t)
for i in a:
    print(i.idx, end=' ')
print('')
time, tot = 0, 0
for i in range(n):
    tot += time
    time += a[i].t
print('%.2f' % (tot / n))
