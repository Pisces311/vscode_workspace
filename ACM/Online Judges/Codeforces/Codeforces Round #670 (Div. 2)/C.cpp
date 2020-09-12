#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
int sub[maxn], fa[maxn];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    fill(sub + 1, sub + n + 1, 1);
}

int dfs(int u, int f) {
    fa[u] = f;
    for (int v : g[u]) {
        if (v != f) {
            sub[u] += dfs(v, u);
        }
    }
    return sub[u];
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (sub[i] == n - sub[i]) {
            for (int j : g[i]) {
                if (j != fa[i]) {
                    cout << i << ' ' << j << '\n';
                    cout << fa[i] << ' ' << j << '\n';
                    return;
                }
            }
        }
    }
    cout << 1 << ' ' << g[1][0] << '\n';
    cout << 1 << ' ' << g[1][0] << '\n';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        init();
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (int v : g[1]) sub[1] += dfs(v, 1);
        solve();
    }

    return 0;
}