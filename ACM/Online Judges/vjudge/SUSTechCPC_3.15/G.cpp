#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int N, Q;
int dfn[maxn], pos[maxn], fa[maxn][20], gfa[maxn], dep[maxn];
int sz[maxn], son[maxn], cut[maxn], num[maxn], times;
vector<int> G[maxn];
set<int> S[maxn];

void dfs(int u, int f, int two) {
    dfn[u] = ++times;
    pos[times] = u;
    dep[u] = dep[f] + 1;
    if (dep[u] == 2) two = u;
    if (two) gfa[u] = two;
    for (int i = 0; i < G[u].size(); i++)
        if (G[u][i] != f) dfs(G[u][i], u, two), son[u] += sz[G[u][i]];
    if (!son[u])
        sz[u] = 1;
    else
        sz[u] = son[u];
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 18; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 18; i >= 0; i--)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int ans1, ans2;
int tmp[maxn];

int main() {
    freopen("gangsters.in", "r", stdin);
    freopen("gangsters.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        cin >> fa[i][0];
        G[fa[i][0]].push_back(i);
    }
    for (int i = 1; i <= 18; i++)
        for (int j = 1; j <= N; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
    dfs(1, 0, 0);
    char op;
    int x;
    while (Q--) {
        cin >> op >> x;
        int t = gfa[x];
        if (op == '+') {
            if (S[t].empty())
                ans1++;
            else
                ans2 -= tmp[t];
            S[t].insert(dfn[x]);
            int Lca = LCA(pos[*S[t].begin()], pos[*S[t].rbegin()]);
            cut[t] = Lca;
            num[t]++;
            tmp[t] = (sz[cut[t]] - num[t]);
            ans2 += tmp[t];
        } else {
            ans2 -= tmp[t];
            tmp[t] = 0;
            S[t].erase(dfn[x]);
            num[t]--;
            if (S[t].empty())
                ans1--, cut[t] = 0;
            else {
                int Lca = LCA(pos[*S[t].begin()], pos[*S[t].rbegin()]);
                cut[t] = Lca;
                tmp[t] = (sz[cut[t]] - num[t]);
                ans2 += tmp[t];
            }
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }

    return 0;
}