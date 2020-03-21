import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


n = int(input())
fa = [0] * (n + 1)
idx = [i for i in range(n + 1)]
dis = [n] * (n + 1)
depth = [0] * (n + 1)
for i in range(2, n + 1):
    fa[i] = int(input())
    depth[i] = depth[fa[i]] + 1
idx[1:] = sorted(idx[1:], key=lambda i: depth[i], reverse=True)
ans = 0
for i in range(1, n + 1):
    u = idx[i]
    v = fa[u]
    w = fa[v]
    dis[u] = min(dis[u], dis[v] + 1, dis[w] + 2)
    if dis[u] > 2:
        dis[w], dis[v], dis[u] = 0, 1, 2
        dis[fa[w]], dis[fa[fa[w]]] = 1, 2
        ans += 1
print(ans)
