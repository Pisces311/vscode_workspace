#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e4 + 5;
constexpr int maxq = 5e4 + 5;

struct Edge {
    int u, v, next;
} edge[maxn];

struct Query {
    int x, y, lca;
} q[maxq];

int n, p, tot;
bool vis[maxn], broke[maxn];
int head[maxn], depth[maxn], f[maxn][20];

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
    memset(broke, false, sizeof(broke));
    memset(vis, false, sizeof(vis));
    memset(depth, 0, sizeof(depth));
    memset(f, 0, sizeof(f));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

//获得倍增数组f和深度数组depth
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    depth[u] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
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

void update(int u) {
    broke[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!broke[v] && v != f[u][0]) {
            update(v);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        init();
        int u, v;
        for (int i = 1; i <= n; ++i) {
            cin >> u >> v;
            ++u, ++v;
            add_edge(u, v);
            add_edge(v, u);
        }
        bfs(1);
        cin >> p;
        for (int i = 1; i <= p; ++i) {
            cin >> q[i].x >> q[i].y;
            ++q[i].x, ++q[i].y;
            q[i].lca = lca(q[i].x, q[i].y);
        }
        sort(q + 1, q + p + 1, [](const Query& a, const Query& b) {
            return depth[a.lca] > depth[b.lca];
        });
        int ans = 0;
        for (int i = 1; i <= p; ++i) {
            if (!broke[q[i].x] && !broke[q[i].y]) {
                ++ans;
                update(q[i].lca);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}