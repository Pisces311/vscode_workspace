#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct Node {
    int id, dis, size;
    bool operator<(const Node& a) const { return size - dis > a.size - a.dis; }
} node[maxn];

int n, k;
bool ind[maxn];
int dis[maxn];
vector<int> g[maxn];

void get(int u, int d, int fa) {
    node[u].dis = d;
    node[u].size = 1;
    for (int v : g[u]) {
        if (v != fa) {
            get(v, d + 1, u);
            node[u].size += node[v].size;
        }
    }
}

void dfs(int u, int d, int fa) {
    dis[u] = d;
    if (ind[u]) --dis[u];
    for (int v : g[u]) {
        if (v != fa) {
            dfs(v, dis[u] + 1, u);
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

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) node[i].id = i;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    get(1, 1, -1);
    sort(node + 1, node + n + 1);
    for (int i = n - k + 1; i <= n; ++i) ind[node[i].id] = true;
    dfs(1, 1, -1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        if (ind[i]) ans += dis[i];
    cout << ans << '\n';

    return 0;
}