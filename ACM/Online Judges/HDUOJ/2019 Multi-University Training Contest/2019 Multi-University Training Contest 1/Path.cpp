#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 2e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm];

struct node {
    int v;
    ll dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int t, n, m, tot, S, T;
int head[maxn], depth[maxn], cur[maxn];
ll dis[maxn];
bool vis[maxn];
vector<node> g[maxn];

inline void init() {
    tot = -1;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= n; ++i) dis[i] = LLONG_MAX;
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void dijkstra(int s) {
    priority_queue<node> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        for (int i = 0; i < g[t.v].size(); ++i)
            if (!vis[g[t.v][i].v]) {
                int v = g[t.v][i].v;
                if (dis[v] > dis[t.v] + g[t.v][i].dis) {
                    dis[v] = dis[t.v] + g[t.v][i].dis;
                    pq.push({v, dis[v]});
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
    memset(depth, 0, sizeof(depth));
    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = head[f]; i != -1; i = edge[i].next) {
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

ll dinic() {
    ll ans = 0;
    while (bfs()) {
        for (int i = S; i <= T; ++i) cur[i] = head[i];
        while (int d = dfs(S, inf)) ans += d;
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
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
        }
        dijkstra(1);
        for (int i = 1; i <= n; ++i) {
            for (node j : g[i]) {
                if (dis[i] + j.dis == dis[j.v]) {
                    add_edge(i, j.v, j.dis);
                    add_edge(j.v, i, 0);
                }
            }
        }
        S = 1, T = n;
        printf("%lld\n", dinic());
    }

    return 0;
}