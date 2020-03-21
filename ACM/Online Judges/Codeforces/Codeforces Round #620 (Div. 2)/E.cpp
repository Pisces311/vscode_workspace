#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxm];

int n, q, tot;
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
    for (int i = 22; i >= 0; --i)
        if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 22; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    bfs(1);
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int ab = depth[a] + depth[b] - 2 * depth[lca(a, b)];
        int axyb = depth[a] + depth[x] - 2 * depth[lca(a, x)] + 1 + depth[y] +
                   depth[b] - 2 * depth[lca(y, b)];
        int ayxb = depth[a] + depth[y] - 2 * depth[lca(a, y)] + 1 + depth[x] +
                   depth[b] - 2 * depth[lca(x, b)];
        if (ab <= k && (k - ab) % 2 == 0)
            cout << "YES\n";
        else if (axyb <= k && (k - axyb) % 2 == 0)
            cout << "YES\n";
        else if (ayxb <= k && (k - ayxb) % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}