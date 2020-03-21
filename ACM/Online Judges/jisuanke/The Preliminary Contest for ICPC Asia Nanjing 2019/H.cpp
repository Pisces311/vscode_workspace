#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e2 + 5;

struct node {
    int v;
    ll w;
};

int t, n, m, S, T;
vector<node> g[maxn];
ll ans, dis[maxn];

inline void init() {
    for (int i = 0; i < n; ++i) g[i].clear();
}

void dfs(int u) {
    if (u == S)
        ans = min(ans, dis[u]);
    else
        for (node v : g[u])
            if (dis[v.v] > dis[u] + v.w) {
                dis[v.v] = dis[u] + v.w;
                dfs(v.v);
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
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        for (int i = 1; i <= 6; ++i) {
            cin >> S >> T;
            ans = LLONG_MAX;
            for (int i = 0; i < n; ++i) dis[i] = LLONG_MAX;
            dis[T] = 0;
            dfs(T);
            cout << -ans << '\n';
            g[S].push_back({T, -ans});
        }
    }

    return 0;
}