#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxm << 1], edge0[maxm << 1];

int T, n, m, q, tot, tot0, order, scc;
int head[maxn], head0[maxn], dfn[maxn], low[maxn], belong[maxn], in[maxn];
int depth[maxn], f[maxn][20], parent[maxn];
bool vis[maxn], vis_e[maxm << 1];
stack<int> stk;

inline void init() {
    order = scc = 0;
    tot = tot0 = -1;
    memset(head, -1, sizeof(head));
    memset(head0, -1, sizeof(head0));
    memset(dfn, 0, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    memset(vis_e, false, sizeof(vis_e));
    memset(f, 0, sizeof(f));
    memset(parent, -1, sizeof(parent));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

inline void add_edge0(int u, int v) {
    edge0[++tot0] = {u, v, head0[u]};
    head0[u] = tot0;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++order;
    stk.push(u);
    in[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (vis_e[i] || vis_e[i ^ 1]) continue;
        if (!dfn[v]) {
            vis_e[i] = true;
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        int t;
        do {
            t = stk.top();
            stk.pop();
            in[t] = false;
            belong[t] = scc;
        } while (t != u);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    depth[u] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head0[t]; i != -1; i = edge0[i].next) {
            int v = edge0[i].v;
            if (!vis[v]) {
                depth[v] = depth[t] + 1;
                vis[v] = 1;
                f[v][0] = t;
                for (int j = 1; j <= 16; ++j) f[v][j] = f[f[v][j - 1]][j - 1];
                q.push(v);
            }
        }
    }
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = 16; i >= 0; --i)
        if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 16; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] >= 0; pos = parent[pos])
        ;
    while (pos != x) {
        int tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(int u, int v) {
    int tmp = parent[u] + parent[v];
    if (u < v) {
        parent[u] = tmp;
        parent[v] = u;
    } else {
        parent[u] = v;
        parent[v] = tmp;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) tarjan(i);
        for (int i = 1; i <= n; ++i)
            for (int j = head[i]; j != -1; j = edge[j].next) {
                int v = edge[j].v;
                if (belong[i] == belong[v]) continue;
                add_edge0(belong[i], belong[v]);
                int x = find(belong[i]), y = find(belong[v]);
                if (x != y) Union(x, y);
            }
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) bfs(i);
        for (int i = 1; i <= q; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u = belong[u], v = belong[v], w = belong[w];
            if (find(u) == find(v) && find(u) == find(w)) {
                int uv = lca(u, v), vw = lca(v, w), uw = lca(u, w);
                if ((vw == uv && uw == u) || (vw == uw && uv == u))
                    printf("Yes\n");
                else
                    printf("No\n");
            } else
                printf("No\n");
        }
    }

    return 0;
}