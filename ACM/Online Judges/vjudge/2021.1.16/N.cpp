#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct Edge {
    int id, u, v;
} edge[maxn];

struct block {
    int st, id, ed;
};

int n;
vector<Edge> g[maxn];
set<int> se;
map<int, int> ma, rev;
vector<block> blk;

bool vis[maxn];

inline void init() {
    se.clear();
    ma.clear();
    blk.clear();
    rev.clear();
    for (int i = 1; i <= 2 * n; ++i) g[i].clear();
    memset(vis + 1, false, sizeof(bool) * 2 * n);
}

void dfs(int u, block &x) {
    vis[u] = true;
    for (Edge e : g[u]) {
        int v = e.v;
        if (!vis[v]) {
            x.id = e.id;
            x.ed = v;
            dfs(v, x);
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

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        int u, v;
        for (int i = 1; i <= n; ++i) {
            cin >> u >> v;
            se.insert(u);
            se.insert(v);
            edge[i] = {i, u, v};
        }
        int p = 0;
        for (int i : se) {
            ma[i] = ++p;
            rev[p] = i;
        }
        for (int i = 1; i <= n; ++i) {
            u = ma[edge[i].u], v = ma[edge[i].v];
            g[u].push_back({i, u, v});
            g[v].push_back({i, v, u});
        }
        for (int i = 1; i <= p; ++i)
            if (!vis[i]) {
                block b;
                b.st = i;
                dfs(i, b);
                blk.push_back(b);
            }
        cout << blk.size() - 1 << '\n';
        for (int i = 0; i < blk.size() - 1; ++i) {
            cout << blk[i].id << ' ' << rev[blk[i].ed] << ' '
                 << rev[blk[i + 1].st] << '\n';
        }
    }

    return 0;
}