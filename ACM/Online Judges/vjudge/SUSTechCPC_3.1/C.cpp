#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int maxn = 1e5 + 5;

int T, n, m;
vector<int> pre[maxn], suc[maxn];
vector<pii> edge;
bool vis[maxn];
set<pii> remain;

inline void init() {
    for (int i = 1; i <= n; ++i) {
        pre[i].clear();
        suc[i].clear();
    }
    edge.clear();
    remain.clear();
}

void dfs1(int u) {
    vis[u] = true;
    for (int v : suc[u]) {
        if (!vis[v]) {
            remain.insert(make_pair(u, v));
            dfs1(v);
        }
    }
}

void dfs2(int v) {
    vis[v] = true;
    for (int u : pre[v]) {
        if (!vis[u]) {
            remain.insert(make_pair(u, v));
            dfs2(u);
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

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            edge.push_back(make_pair(u, v));
            pre[v].push_back(u);
            suc[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) vis[i] = false;
        dfs1(1);
        for (int i = 1; i <= n; ++i) vis[i] = false;
        dfs2(1);
        int cnt = 0, sz = remain.size();
        for (pii p : edge) {
            if (remain.find(p) == remain.end()) {
                if (sz + cnt < 2 * n)
                    cnt++;
                else
                    cout << p.first << ' ' << p.second << '\n';
            }
        }
    }

    return 0;
}