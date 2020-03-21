#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, m;
vector<int> g[maxn];
bool vis[maxn];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) q.push(v);
            vis[v] = true;
        }
    }
}

bool judge() {
    for (int i = 1; i <= n - 1; ++i)
        if (!vis[i]) return false;
    return true;
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
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool flag = true;
        for (int i = 1; i <= n - 1; ++i) {
            for (int j = 1; j <= n; ++j) vis[j] = false;
            bfs(i);
            if (!vis[n]) {
                cout << i << ' ';
                flag = false;
            }
        }
        if (flag)
            cout << "Yes" << '\n';
        else
            cout << '\n';
    }

    return 0;
}