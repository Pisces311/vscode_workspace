#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e3 + 5;
const int maxm = 2e5 + 5;

struct Edge {
    int u, v, w, next;
} edge[maxm];

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int t, n, m, u, v, w, tot, S, T;
int head[maxm], depth[maxn], cur[maxn], dis[maxn];
bool vis[maxn];
vector<node> g[maxn];
priority_queue<node> pq;

inline void init() {
    tot = -1;
    mem(head, -1);
    mem(vis, false);
    up(i, 1, n) dis[i] = INT_MAX;
    up(i, 1, n) g[i].clear();
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void dijkstra(int s) {
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        for (node i : g[t.v])
            if (!vis[i.v]) {
                if (dis[i.v] > dis[t.v] + i.w) {
                    dis[i.v] = dis[t.v] + i.w;
                    pq.push({i.v, dis[i.v]});
                }
            }
    }
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
        up(i, 1, n) cur[i] = head[i];
        while (int d = dfs(S, INT_MAX)) ans += d;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init();
        up(i, 1, m) {
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
        }
        scanf("%d %d", &S, &T);
        dijkstra(S);
        up(i, 1, n) for (node j : g[i]) {
            if (dis[i] + j.w == dis[j.v]) {
                add_edge(i, j.v, 1);
                add_edge(j.v, i, 0);
            }
        }
        printf("%d\n", dinic());
    }

    return 0;
}