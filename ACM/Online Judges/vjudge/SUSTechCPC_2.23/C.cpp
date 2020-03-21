#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int tot, head[maxn];

struct Edge {
    int v, next;
} edge[maxn << 1];

void add_edge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

int num[maxn], son[maxn], fa[maxn];
int x[maxn], y[maxn], order;

void init() {
    tot = -1;
    order = 0;
    memset(head, -1, sizeof(head));
}

void dfs1(int u, int pre) {
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == pre) continue;
        dfs1(v, u);
        num[u] += num[v];
        if (!son[u] || num[v] > num[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int d) {
    x[u] = ++order;
    y[u] = d;
    if (!son[u]) return;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, d + 1);
    }
    dfs2(son[u], d);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    init();
    for (int i = 1, u, v; i <= n - 1; ++i) {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; ++i) cout << x[i] << ' ' << y[i] << '\n';

    return 0;
}
