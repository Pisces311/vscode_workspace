#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int n, m;
bool vis[maxn];
int ans, point, edge;
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    fill(vis + 1, vis + n + 1, false);
}

void dfs(int u, int fa) {
    vis[u] = true;
    ++point;
    edge += g[u].size();
    for (int v : g[u]) {
        if (v != fa) {
            if (!vis[v]) dfs(v, u);
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

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                point = 0, edge = 0;
                dfs(i, -1);
                if (edge / 2 > point) ans += edge / 2 - point;
            }
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}