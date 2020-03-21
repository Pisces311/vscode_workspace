#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int N, M, tot, u, v, w, order, scc;
int head[maxn], dfn[maxn], low[maxn], belong[maxn], in[maxn];
int dis[maxn];
stack<int> stk;

inline void init() {
    order = scc = 0;
    tot = -1;
    mem(head, -1);
    mem(dis, inf);
    mem(dfn, 0);
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++order;
    stk.push(u);
    in[u] = true;
    link(i, u) {
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
        } while (t != u);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M)) {
        init();
        up(i, 1, M) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
        }
        tarjan(0);
        dis[belong[0]] = 0;
        up(i, 0, tot) {
            int u = edge[i].u, v = edge[i].v;
            if (belong[u] != belong[v])
                dis[belong[v]] = min(dis[belong[v]], edge[i].w);
        }
        printf("%d\n", accumulate(dis + 1, dis + scc + 1, 0));
    }

    return 0;
}