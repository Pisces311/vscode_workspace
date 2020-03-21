from queue import PriorityQueue
from queue import Queue


INF = 0x3f3f3f3f


class node:
    def __init__(self, id, w):
        self.id = id
        self.w = w

    def __lt__(self, other):
        return True if self.w < other.w else False


def Prim(n: int, S: int, para_edges: list) -> list:
    '''Return a list that contains the edges in the spanning tree.

    'n' is the total number of nodes, S is an arbitrary start point
    in the graph, para_edges is the list of the graph edges.

    '''
    print("Start Spanning Tree Algorithm...")

    Graph = [[] for i in range(n + 1)]
    for edge in para_edges:
        u, v = edge
        Graph[u].append(node(v, 1))

    dis = [INF for i in range(n + 1)]
    dis[S] = 0

    pre = [-1] * (n + 1)

    pq = PriorityQueue()
    pq.put(node(S, 0))
    while not pq.empty():
        top = pq.get()
        for i in Graph[top.id]:
            if dis[i.id] > i.w:
                dis[i.id] = i.w
                pre[i.id] = top.id
                pq.put(node(i.id, dis[i.id]))

    tree_edges = []
    for i in range(n + 1):
        if pre[i] != -1:
            tree_edges.append((i, pre[i]))
            tree_edges.append((pre[i], i))

    return tree_edges


def query(n: int, S: int, tree_edges: list) -> dict:
    '''Return a dictionary that describes the children of every node.

    'n' is the total number of nodes, S is an arbitrary start point
    in the graph, tree_edges is the list of the tree edges.

    '''
    Graph = [[] for i in range(n + 1)]
    for edge in tree_edges:
        u, v = edge
        Graph[u].append(node(v, 1))

    neighbours = {}
    for i in range(n + 1):
        neighbours[i] = []

    q = Queue()
    q.put(node(S, -1))
    while not q.empty():
        top = q.get()
        for i in Graph[top.id]:
            if i.id != top.w:
                neighbours[top.id].append(i.id)
                q.put(node(i.id, top.id))

    return neighbours


if __name__ == "__main__":
    n, m = map(int, input().split())
    edges = []
    for i in range(m):
        u, v = map(int, input().split())
        edges.append((u, v))
        edges.append((v, u))
    tree = Prim(n, 1, edges)
    print(tree)
    print(query(n, 1, tree))
    print(query(n, 2, tree))


'''
9 11
1 2
1 3
4 5
3 4
2 5
5 6
4 8
6 8
6 7
7 8
7 9
'''
