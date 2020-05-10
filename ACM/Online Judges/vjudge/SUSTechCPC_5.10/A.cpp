#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, n;
ll a[maxn];
bool vis[maxn];
int cx[maxn], cy[maxn];
int edge[maxn][maxn];

int dfs(int u) {
    for (int v = 1; v <= n; ++v) {
        if (edge[u][v] && !vis[v]) {
            vis[v] = true;
            if (cy[v] == -1 || dfs(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int sum = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i = 1; i <= n; ++i) {
        if (cx[i] == -1) {
            memset(vis, false, sizeof(vis));
            sum += dfs(i);
        }
    }
    return sum;
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
        memset(edge, 0, sizeof(edge));
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (a[j] % a[i] == 0) edge[i][j] = 1;
        cout << n - hungary() << '\n';
    }

    return 0;
}