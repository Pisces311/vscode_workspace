#include <string.h>
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxn];

int n, m;
int order, scc, tot;
int head[maxn];
int dfn[maxn], low[maxn], id[maxn], num[maxn], in[maxn];
stack<int> stk;

inline void init() {
    tot = -1;
    order = scc = 0;
    memset(head, -1, sizeof(head));
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
            num[scc]++;
        } while (t != u);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
    if (scc == 1)
        cout << "Bravo\n";
    else
        cout << "ovarB\n";

    return 0;
}