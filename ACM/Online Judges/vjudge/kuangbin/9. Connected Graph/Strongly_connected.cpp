#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxn];

int T, N, M, tot, u, v, order, scc, min_num;
ll ans;
int head[maxn], dfn[maxn], low[maxn], belong[maxn], num[maxn], indeg[maxn],
    outdeg[maxn];
bool in[maxn];
stack<int> stk;

inline void init() {
    ans = 0;
    order = scc = 0;
    tot = -1;
    min_num = INT_MAX;
    mem(head, -1);
    mem(dfn, 0);
    mem(num, 0);
    mem(indeg, 0);
    mem(outdeg, 0);
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
            belong[t] = scc;
            num[scc]++;
        } while (t != u);
    }
}

void rebuild() {
    up(i, 1, N) for (int j = head[i]; j != -1; j = edge[j].next) {
        int u = belong[edge[j].u], v = belong[edge[j].v];
        if (u == v) continue;
        ++indeg[u];
        ++outdeg[v];
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    up(case_num, 1, T) {
        scanf("%d %d", &N, &M);
        init();
        up(i, 1, M) {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }
        up(i, 1, N) if (!dfn[i]) tarjan(i);
        rebuild();
        up(i, 1, scc) if (indeg[i] * outdeg[i] == 0) min_num =
            min(min_num, num[i]);
        ans = 1ll * N * (N - 1) - M - 1ll * (N - min_num) * min_num;
        printf("Case %d: %lld\n", case_num, (scc == 1 ? -1 : ans));
    }

    return 0;
}