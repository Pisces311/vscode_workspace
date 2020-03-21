from queue import PriorityQueue

INF = 0x3f3f3f3f


class node:
    def __init__(self, id, w):
        self.id = id
        self.w = w

    def __lt__(self, other):
        return True if self.w < other.w else False


def Dijkstra(n: int, S: int, para_edges: list) -> dict:

    Graph = [[] for i in range(n + 1)]
    for edge in para_edges:
        u, v = edge
        Graph[u].append(node(v, 1))

    dis = [INF for i in range(n + 1)]
    dis[S] = 0

    via = {}
    pre = [0 for i in range(n + 1)]
    paths = [[] for i in range(n + 1)]
    paths[S].append(S)

    pq = PriorityQueue()
    pq.put(node(S, 0))
    while not pq.empty():
        top = pq.get()
        if dis[top.id] < top.w:
            continue
        if top.id != S:
            paths[top.id] = paths[pre[top.id]].copy()
            paths[top.id].append(top.id)
        for i in Graph[top.id]:
            if dis[i.id] > dis[top.id] + i.w:
                dis[i.id] = dis[top.id] + i.w
                pre[i.id] = top.id
                if top.id != S:
                    via[i.id] = via[top.id]
                else:
                    via[i.id] = i.id
                pq.put(node(i.id, dis[i.id]))
    return via, paths


if __name__ == "__main__":
    n, m = map(int, input().split())
    lst = []
    for i in range(m):
        u, v = map(int, input().split())
        lst.append((u, v))
        lst.append((v, u))
    a, b = Dijkstra(n, 1, lst)
    print(b)
