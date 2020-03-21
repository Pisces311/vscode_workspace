#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, m;
int col[maxn];
vector<int> g[maxn];
bool ok;

inline void init() {
    ok = true;
    memset(col, 0, sizeof(col));
    for (int i = 1; i <= n; ++i) g[i].clear();
}

void dfs(int u, int c) {
    col[u] = c;
    for (int v : g[u]) {
        if (col[v]) {
            if (col[v] == col[u]) {
                ok = false;
                return;
            }
        } else
            dfs(v, c == 1 ? 2 : 1);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
            if (!col[i] && ok) dfs(i, 1);
        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}