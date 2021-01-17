#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e2 + 5;

int n, m;
int a[maxn][maxn], d[maxn][maxn];
int S[maxn][maxn];
bool vis[maxn];
vector<int> g[maxn];

void bfs(int s) {
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
            S[s][v] = max(S[s][v], d[u][v]);
        }
    }
}

bool prior(int i) {
    for (int j = 1; j <= m; ++j) {
        if (S[i][j] < S[j][i]) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (!a[i][j]) a[i][j] = 1e6 + 1;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n; ++k)
                if (a[k][i] < a[k][j]) ++d[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] > d[j][i]) g[i].push_back(j);
        }
    }
    for (int i = 1; i <= m; ++i) {
        memset(vis, false, sizeof(vis));
        bfs(i);
    }
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
        if (prior(i)) ans.push_back(i);
    }
    for (int i : ans) cout << i << ' ';

    return 0;
}