#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 5;

struct node {
    int v;
    ll w;
    bool operator<(const node& a) const { return w < a.w; }
};

struct path {
    int u, id;
    ll w;
    bool operator<(const path& a) const { return w > a.w; }
};

int t, n, m, q, u, v, kmost;
int ks[maxn];
ll w, ans[maxn];
vector<node> g[maxn];

inline void init() {
    kmost = -1;
    for (int i = 0; i <= n; ++i) g[i].clear();
}

void solve() {
    priority_queue<path> pq;
    for (int i = 1; i <= n; ++i)
        if (g[i].size()) pq.push({i, 0, g[i][0].w});
    int cnt = 0;
    while (cnt < kmost) {
        path cur = pq.top();
        pq.pop();
        u = cur.u;
        int id = cur.id;
        ans[++cnt] = cur.w;
        if (id < (int)g[u].size() - 1)
            pq.push({u, id + 1, cur.w - g[u][id].w + g[u][id + 1].w});
        v = g[u][id].v;
        if (g[v].size()) pq.push({v, 0, cur.w + g[v][0].w});
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m >> q;
        init();
        for (int i = 1; i <= m; ++i) {
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
        for (int i = 1; i <= q; ++i) {
            cin >> ks[i];
            kmost = max(kmost, ks[i]);
        }
        solve();
        for (int i = 1; i <= q; ++i) cout << ans[ks[i]] << '\n';
    }

    return 0;
}