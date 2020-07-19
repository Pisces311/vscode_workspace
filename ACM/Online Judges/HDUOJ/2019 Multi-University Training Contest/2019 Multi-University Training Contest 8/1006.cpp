#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n;
int a[maxn], b[maxn], dif[maxn];
ll dp[maxn][2];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
}

void dfs(int u, int pre, int turn) {
    ll mi = LLONG_MAX, ma = LLONG_MIN;
    dp[u][0] = dp[u][1] = dif[u];
    for (int v : g[u]) {
        dfs(v, u, turn == 1 ? 0 : 1);
        mi = min(mi, dp[v][0]);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i) dif[i] = a[i] - b[i];
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, -1, 0);
        dfs(1, -1, 1);
    }

    return 0;
}