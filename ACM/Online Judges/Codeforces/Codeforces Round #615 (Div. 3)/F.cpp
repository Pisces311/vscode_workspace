#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
const int maxm = 4e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxm];

int n, tot;
bool vis[maxn];
int head[maxn], depth[maxn], f[maxn][20];

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

void dfs1(int u, int d) {
    depth[u] = d;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!depth[v]) {
            dfs1(v, d + 1);
        }
    }
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

int qpow(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) ret *= a;
        b /= 2;
        a *= a;
    }
    return ret;
}

int lca(int x, int y) {
    int len = 0;
    if (depth[x] > depth[y]) {
        for (int i = 16; i >= 0; --i)
            if (depth[f[x][i]] >= depth[y]) {
                x = f[x][i];
                len += qpow(2, i);
            }
    } else
        for (int i = 16; i >= 0; --i)
            if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return len;
    for (int i = 16; i >= 0; --i)
        if (f[x][i] != f[y][i]) {
            x = f[x][i], y = f[y][i];
            len += qpow(2, i);
        }
    return len + 1;
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
    dfs1(1, 1);
    int max1 = -1, u = -1;
    for (int i = 1; i <= n; ++i) {
        if (depth[i] > max1) {
            max1 = depth[i];
            u = i;
        }
    }
    memset(depth, 0, sizeof(depth));
    dfs1(u, 1);
    int max2 = -1, v = -1;
    for (int i = 1; i <= n; ++i) {
        if (depth[i] > max2) {
            max2 = depth[i];
            v = i;
        }
    }
    int ans = depth[v] - depth[u];
    memset(depth, 0, sizeof(depth));
    bfs(u);
    int tmp = -1, w = -1;
    for (int i = 1; i <= n; ++i) {
        if (i != u && i != v) {
            int cur = lca(i, v);
            if (cur > tmp) {
                tmp = cur;
                w = i;
            }
        }
    }
    cout << ans + tmp << '\n';
    cout << u << ' ' << v << ' ' << w << '\n';

    return 0;
}