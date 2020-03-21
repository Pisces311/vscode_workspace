#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;
const int maxm = 2e6 + 5;

struct Edge {
    int v, next;
} edge[maxm];

int N, M, u, v, tot, order, scc, max_len, pos;
int head[maxm], low[maxn], dfn[maxn], belong[maxn];
bool vis[maxm], in[maxn], vis0[maxn];
int stk[maxn], top;
vector<int> g[maxn];

inline void init() {
    order = scc = top = 0;
    tot = -1;
    up(i, 1, N) g[i].clear();
    mem(dfn, 0);
    mem(head, -1);
    mem(vis, false);
}

inline void add_edge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++order;
    stk[top++] = u;
    in[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[i] || vis[i ^ 1]) continue;
        if (!dfn[v]) {
            vis[i] = true;
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        int t;
        do {
            t = stk[--top];
            in[t] = false;
            belong[t] = scc;
        } while (t != u);
    }
}

void rebuild() {
    up(i, 1, N) for (int j = head[i]; j != -1; j = edge[j].next) {
        int u = belong[i], v = belong[edge[j].v];
        if (u == v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u, int d) {
    vis0[u] = true;
    if (d > max_len) {
        pos = u;
        max_len = d;
    }
    up(i, 0, (int)g[u].size() - 1) if (!vis0[g[u][i]]) dfs(g[u][i], d + 1);
}

void solve() {
    mem(vis0, false);
    max_len = 0;
    dfs(1, 0);
    mem(vis0, false);
    max_len = 0;
    dfs(pos, 0);
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M)) {
        if (N == 0 && M == 0) break;
        init();
        up(i, 1, M) {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        tarjan(1);
        rebuild();
        solve();
        printf("%d\n", scc - 1 - max_len);
    }

    return 0;
}