import queue

dic = {0: 'A', 'A': 0, 1: 'B', 'B': 1, 2: 'C',
       'C': 2, 3: 'D', 'D': 3, 4: 'E', 'E': 4}
g = [[] for i in range(5)]
ind = [0 for i in range(5)]
for i in range(5):
    sta = input()
    if sta[1] == '<':
        g[dic[sta[0]]].append(dic[sta[2]])
        ind[dic[sta[2]]] += 1
    else:
        g[dic[sta[2]]].append(dic[sta[0]])
        ind[dic[sta[0]]] += 1
q = queue.Queue(10)
for i in range(5):
    if ind[i] == 0:
        q.put(i)
ans = []
while not q.empty():
    u = q.get()
    ans.append(dic[u])
    for v in g[u]:
        ind[v] -= 1
        if ind[v] == 0:
            q.put(v)
for i in range(5):
    if ind[i] != 0:
        print('impossible')
        break
else:
    print(''.join(ans))
