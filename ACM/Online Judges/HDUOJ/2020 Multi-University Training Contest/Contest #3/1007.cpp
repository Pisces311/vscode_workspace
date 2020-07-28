#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e1 + 5;
constexpr int inf = 0x3f3f3f3f;

struct node {
    int id, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int T, n, m, ans;
int g[maxn][maxn], dis[maxn], pre[10][maxn];
bool vis[maxn];

void dfs(int m) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(pre[m], 0, sizeof(pre[m]));
    priority_queue<node> pq;
    pq.push({1, 0});
    dis[1] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        for (int i = 1; i <= n; ++i) {
            if (dis[i] > dis[t.id] + g[t.id][i]) {
                dis[i] = dis[t.id] + g[t.id][i];
                pq.push({i, dis[i]});
                pre[m][i] = t.id;
            }
        }
    }
    if (!m) {
        ans = max(ans, dis[n]);
        return;
    }
    int u, v;
    for (u = n; u != 1; u = v) {
        v = pre[m][u];
        int tmp = g[u][v];
        g[u][v] = g[v][u] = inf;
        dfs(m - 1);
        g[u][v] = g[v][u] = tmp;
    }
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
        cin >> n >> m;
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            int u, vis, w;
            cin >> u >> vis >> w;
            g[u][vis] = g[vis][u] = w;
        }
        ans = 0;
        dfs(m);
        cout << ans << '\n';
    }

    return 0;
}