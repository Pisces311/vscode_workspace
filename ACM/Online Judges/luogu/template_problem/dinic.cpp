#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e4 + 5;
const int maxm = 2e5 + 5;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int N, M, S, T, tot, u, v, w;
int head[maxm], depth[maxn], cur[maxn];

void init() {
    tot = -1;
    mem(head, -1);
}

void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

int dfs(int u, int flow) {
    if (u == T) return flow;
    for (int& i = cur[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if ((depth[v] == depth[u] + 1) && (edge[i].w != 0)) {
            int di = dfs(v, min(flow, edge[i].w));
            if (di > 0) {
                edge[i].w -= di;
                edge[i ^ 1].w += di;
                return di;
            }
        }
    }
    return 0;
}

bool bfs() {
    queue<int> q;
    mem(depth, 0);
    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        link(i, f) {
            int v = edge[i].v;
            if ((depth[v] == 0) && edge[i].w > 0) {
                depth[v] = depth[f] + 1;
                q.push(v);
            }
        }
    }
    if (depth[T] > 0) return true;
    return false;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        up(i, 1, N) cur[i] = head[i];
        while (int d = dfs(S, INT_MAX)) ans += d;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    init();
    scanf("%d %d %d %d", &N, &M, &S, &T);
    up(i, 1, M) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, 0);
    }
    printf("%d\n", dinic());

    return 0;
}