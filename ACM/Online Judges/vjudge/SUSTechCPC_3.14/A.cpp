#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;
constexpr int maxm = 1e6 + 5;

struct Edge {
    int u, v, next;
} edge[maxm];

int n, m, tot;
int order, scc;
int head[maxn];
int dfn[maxn], low[maxn], id[maxn], in[maxn];
stack<int> stk;

inline void init() {
    tot = order = scc = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
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
        } while (t != u);
    }
}

bool check() {
    for (int i = 0; i < 2 * n; i += 2)
        if (id[i] == id[i + 1]) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        init();
        cin >> m;
        int A1, A2, C1, C2;
        for (int i = 1; i <= m; ++i) {
            cin >> A1 >> A2 >> C1 >> C2;
            int p1 = A1 * 2 + C1;
            int p2 = A2 * 2 + C2;
            add_edge(p1, p2 ^ 1);
            add_edge(p2, p1 ^ 1);
        }
        for (int i = 0; i < 2 * n; ++i)
            if (!dfn[i]) tarjan(i);
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}