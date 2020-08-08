#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, t;
bool vis[maxn];
int deg[maxn], depth[maxn], f[maxn][20];
vector<int> g[maxn];

//获得倍增数组f和深度数组depth
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    depth[u] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int v : g[t]) {
            if (!vis[v]) {
                depth[v] = depth[t] + 1;
                vis[v] = 1;
                f[v][0] = t;
                for (int j = 1; j <= 18; ++j) f[v][j] = f[f[v][j - 1]][j - 1];
                q.push(v);
            }
        }
    }
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = 18; i >= 0; --i)
        if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 18; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int solve() {
    int up = depth[n] - depth[1] - t;
    if (up <= 0) return 0;
    int mid = n;
    while (up--) mid = f[mid][0];
    int ans = -1, cur;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            int imid = lca(i, mid), in = lca(i, n);
            if (depth[imid] <= depth[mid] && in != n &&
                depth[in] <= depth[mid]) {
                cur = min(depth[n] - depth[mid],
                          (depth[i] + depth[n] - 2 * depth[imid] + 1) / 2);
                ans = max(ans, cur);
            } else if (in != n) {
                int len_up = depth[in] - depth[mid],
                    len_down = depth[n] - depth[in];
                if (2 * len_up < len_down) {
                    cur = min(len_up + (len_up + len_down) - 3 * len_up,
                              (depth[n] + depth[i] - 2 * depth[in] + 1) / 2);
                    ans = max(ans, cur);
                }
            }
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        ++deg[x], ++deg[y];
    }
    bfs(1);
    cout << solve() << '\n';

    return 0;
}