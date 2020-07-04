#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int maxm = 1e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxm];

int T, N, M;
int order, scc, tot;
int head[maxn];
int dfn[maxn], low[maxn], id[maxn], num[maxn], in[maxn];
int indeg[maxn], outdeg[maxn];
stack<int> stk;

inline void init() {
    tot = -1;
    order = scc = 0;
    memset(head, -1, sizeof(head));
    memset(num, 0, sizeof(num));
    memset(dfn, 0, sizeof(dfn));
    memset(indeg, 0, sizeof(indeg));
    memset(outdeg, 0, sizeof(outdeg));
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
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
            id[t] = scc;
            ++num[scc];
        } while (t != u);
    }
}

ll solve() {
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 1; i <= N; ++i)
        if (!dfn[i]) tarjan(i);
    if (scc == 1) return -1;
    for (int i = 1; i <= N; ++i) {
        for (int j = head[i]; j != -1; j = edge[j].next) {
            int u = edge[j].u, v = edge[j].v;
            if (id[u] != id[v]) ++outdeg[id[u]], ++indeg[id[v]];
        }
    }
    int min_size = 1e5;
    for (int i = 1; i <= scc; ++i)
        if (!indeg[i] || !outdeg[i]) min_size = min(min_size, num[i]);
    ll ans = 1ll * N * (N - 1) - M - 1ll * (N - min_size) * min_size;
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        init();
        cout << "Case " << cas << ": " << solve() << '\n';
    }

    return 0;
}