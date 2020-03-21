#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int n, m, order, scc, tot, s;
int head[maxn];
int dfn[maxn], low[maxn], belong[maxn], num[maxn], in[maxn];
ll sum[maxm], val[maxn], dp[maxn];
bool vis[maxn];
stack<int> stk;
vector<pair<int, int> > g[maxn];

inline void init() {
    tot = 0;
    order = scc = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++order;
    stk.push(u);
    in[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        int t;
        do {
            t = stk.top();
            stk.pop();
            in[t] = false;
            belong[t] = scc;
            num[scc]++;
        } while (t != u);
    }
}

ll dfs(int u) {
    if (vis[u]) return dp[u];
    ll ret = 0;
    vis[u] = true;
    for (auto i : g[u]) {
        int v = i.first;
        ret = max(ret, dfs(v) + i.second);
    }
    return dp[u] = ret + val[u];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    init();
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    scanf("%d", &s);
    tarjan(s);
    for (int i = 1; i < maxm; i++) sum[i] = sum[i - 1] + 1ll * i * (i + 1) / 2;
    for (int i = 1; i <= m; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (belong[u] == belong[v]) {
            int x = (int)floor((-1.0 + sqrt(1.0 + 8 * w)) / 2);
            val[belong[u]] += 1ll * (x + 1) * w - sum[x];
        } else
            g[belong[u]].push_back({belong[v], w});
    }
    scanf("%d", &s);
    printf("%lld\n", dfs(belong[s]));

    return 0;
}