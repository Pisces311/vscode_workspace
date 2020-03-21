#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxn << 1];

int n, tot;
bool vis[maxn];
int head[maxn], depth[maxn], f[maxn][25];

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

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
                for (int j = 1; j <= 24; ++j) f[v][j] = f[f[v][j - 1]][j - 1];
                q.push(v);
            }
        }
    }
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = 24; i >= 0; --i)
        if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 24; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    init();
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    bfs(1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            ans += depth[i] + depth[j] - 2 * depth[lca(i, j)] + 1;
        }
    }
    printf("%lld\n", ans);

    return 0;
}