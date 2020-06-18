#include <string.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

struct node {
    int id, dis;
};

int t, n, m, S, T;
bool vis[maxn];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(vis, false, sizeof(vis));
}

int bfs() {
    queue<node> q;
    q.push({S, 0});
    vis[S] = true;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        if (u.id == T) return u.dis;
        for (int v : g[u.id]) {
            if (!vis[v]) {
                q.push({v, u.dis + 1});
                vis[v] = true;
            }
        }
    }
    return -1;
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
        cin >> n >> m >> S >> T;
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << bfs() << '\n';
    }

    return 0;
}