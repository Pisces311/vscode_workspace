#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxn << 1];

int head[maxn];
int N, M, tot, order, a[maxn], fa[maxn];

inline void init() {
    tot = -1;
    order = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

struct SegTreeNode {
    int l, r, val;
} t[maxn << 5];

int m, cnt = 0;
int b[maxn], T[maxn];

int build(int l, int r) {
    int o = ++cnt;
    t[o].val = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        t[o].l = build(l, mid);
        t[o].r = build(mid + 1, r);
    }
    return o;
}

int update(int pre, int l, int r, int x) {
    int o = ++cnt;
    t[o].l = t[pre].l;
    t[o].r = t[pre].r;
    t[o].val = t[pre].val + 1;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (x <= mid)
            t[o].l = update(t[pre].l, l, mid, x);
        else
            t[o].r = update(t[pre].r, mid + 1, r, x);
    }
    return o;
}

int Kth_query(int u, int v, int lca, int fa_lca, int l, int r, int k) {
    if (l >= r) return l;
    int x =
        t[t[u].l].val + t[t[v].l].val - t[t[lca].l].val - t[t[fa_lca].l].val;
    int mid = (l + r) >> 1;
    if (x >= k)
        return Kth_query(t[u].l, t[v].l, t[lca].l, t[fa_lca].l, l, mid, k);
    else
        return Kth_query(t[u].r, t[v].r, t[lca].r, t[fa_lca].r, mid + 1, r,
                         k - x);
}

int depth[maxn], f[maxn][20];
bool vis[maxn];

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

void dfs(int u, int pre) {
    int t = lower_bound(b + 1, b + m + 1, a[u]) - b;
    T[u] = update(T[pre], 1, m, t);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == pre) continue;
        fa[v] = u;
        dfs(v, u);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= N; ++i) b[i] = a[i];
    sort(b + 1, b + N + 1);
    m = unique(b + 1, b + N + 1) - b - 1;
    T[0] = build(1, m);
    dfs(1, 0);
    int lastans = 0;
    bfs(1);
    while (M--) {
        int u, v, k;
        cin >> u >> v >> k;
        u ^= lastans;
        int LCA = lca(u, v);
        cout << (lastans =
                     b[Kth_query(T[u], T[v], T[LCA], T[fa[LCA]], 1, m, k)])
             << '\n';
    }

    return 0;
}