#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e5 + 5;

int T, n;
int fa[maxn], sz[maxn], depth[maxn];
ll tot, ans;
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        sz[i] = 0;
    }
}

void dfs(int u, int d) {
    ++sz[u];
    depth[u] = d;
    for (int v : g[u]) {
        if (v != fa[u]) {
            dfs(v, d + 1);
            sz[u] += sz[v];
        }
    }
}

void dfs2(int u, ll cur) {
    cur += sz[u];
    if (g[u].size() <= 1) ans = max(ans, tot - cur + 1ll * depth[u] * n);
    for (int v : g[u])
        if (v != fa[u]) dfs2(v, cur);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 2; i <= n; ++i) {
            cin >> fa[i];
            g[i].push_back(fa[i]);
            g[fa[i]].push_back(i);
        }
        dfs(1, 1);
        tot = 0, ans = 0;
        for (int i = 1; i <= n; ++i) tot += sz[i];
        dfs2(1, 0);
        cout << ans << '\n';
    }

    return 0;
}