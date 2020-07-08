#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int maxm = 3e5 + 5;

struct Edge {
    int u, v, id, next;
    bool del;
} edge[maxm];

int n, m;
int head[maxn], tot, deg[maxn];
bool vis[maxn];
vector<int> odd, sta, ans[maxn];

inline void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
}

inline void add_edge(int u, int v, int id) {
    edge[tot] = {u, v, id, head[u], false};
    head[u] = tot++;
    edge[tot] = {v, u, -id, head[v], false};
    head[v] = tot++;
}

void find_odd(int u) {
    vis[u] = true;
    if (deg[u] & 1) odd.push_back(u);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!vis[v]) find_odd(v);
    }
}

void dfs(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next)
        if (!edge[i].del) {
            edge[i].del = edge[i ^ 1].del = true;
            dfs(edge[i].v);
            sta.push_back(edge[i].id);
        }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v, i);
            ++deg[u], ++deg[v];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            odd.clear();
            find_odd(i);
            if (odd.size() > 2)
                for (int j = 2; j < odd.size(); j += 2)
                    add_edge(odd[j], odd[j + 1], 0);
            sta.clear();
            int s = odd.size() ? odd[0] : i;
            dfs(s);
            ans[res].clear();
            if (sta.size()) {
                for (int j = sta.size() - 1; j >= 0; j--)
                    if (sta[j]) {
                        if (j < sta.size() - 1 && !sta[j + 1])
                            ans[++res].clear();
                        ans[res].push_back(sta[j]);
                    }
                res++;
            }
        }
        cout << res << '\n';
        for (int i = 0; i < res; ++i) {
            cout << ans[i].size() << ' ';
            for (int j : ans[i]) cout << j << ' ';
            cout << '\n';
        }
    }

    return 0;
}