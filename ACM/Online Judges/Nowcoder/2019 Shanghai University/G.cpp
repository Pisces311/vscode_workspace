#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct Edge {
    int v;
    ll r;
};

ll n, m, s;
vector<Edge> g[maxn];
int in[maxn];
ll num[maxn];
queue<int> q;

ll bfs() {
    for (int i = 1; i <= n; ++i)
        if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (Edge e : g[u]) {
            int v = e.v;
            ll r = e.r;
            num[v] = max(num[v], num[u] + r);
            --in[v];
            if (!in[v]) q.push(v);
        }
    }
    return accumulate(num + 1, num + n + 1, 0ll);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll r;
        cin >> u >> v >> r;
        g[u].push_back({v, r});
        ++in[v];
    }
    ll ret = bfs();
    if (!ret)
        cout << "-1\n";
    else
        cout << s / ret << '\n';

    return 0;
}