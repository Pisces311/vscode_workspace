#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct node {
    int v, w;
};

int n, m;
vector<int> g[maxn << 1];
bool vis[maxn << 1];

void bfs(int s) {
    queue<node> q;
    q.push({s, 0});
    vis[s] = true;
    while (q.size()) {
        node u = q.front();
        q.pop();
        if (u.v == n) {
            cout << u.w << '\n';
            return;
        }
        for (int v : g[u.v])
            if (!vis[v]) {
                q.push({v, u.w + 1});
                vis[v] = true;
            }
    }
    cout << "-1\n";
}

int main() {
#ifdef DEBUG
    freopen("8.in", "r", stdin);
    freopen("8.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int id = n;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 1)
            g[u].push_back(v);
        else {
            g[u].push_back(++id);
            g[id].push_back(v);
        }
    }
    bfs(1);

    return 0;
}