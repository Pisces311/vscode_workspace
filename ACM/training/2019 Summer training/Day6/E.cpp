#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int maxm = 5e2 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
    bool operator==(const Edge& a) const { return u == a.u && v == a.v; }
} edge[maxm << 1];

int n, m, u, v, w, S, T, tot;
int head[maxn], depth[maxn];
vector<Edge> V;

inline void init() {
    tot = -1;
    mem(head, -1);
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

int dfs(int u, int flow) {
    if (u == T) return flow;
    link(i, u) {
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
    while (bfs())
        while (int d = dfs(S, inf)) ans += d;
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    up(i, 1, m) {
        scanf("%d %d %d", &u, &v, &w);
        V.push_back({u, v, w});
    }
    int ans = 0;
    for (Edge i : V) {
        init();
        for (Edge j : V) {
            if (i == j) continue;
            if (j.w < i.w) {
                add_edge(j.u, j.v, 1);
                add_edge(j.v, j.u, 1);
            }
        }
        S = i.u, T = i.v;
        ans += dinic();
    }
    printf("%d\n", ans);

    return 0;
}