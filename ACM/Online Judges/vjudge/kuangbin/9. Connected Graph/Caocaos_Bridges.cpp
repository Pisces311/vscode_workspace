#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e3 + 5;
const int maxm = 2 * maxn * maxn;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int N, M, u, v, w, tot, order, min_val;
bool vis[maxm];
int head[maxm], dfn[maxn], low[maxn];

inline void init() {
    order = 0;
    tot = -1;
    min_val = 10005;
    mem(head, -1);
    mem(dfn, 0);
    mem(vis, false);
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++order;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[i] || vis[i ^ 1]) continue;
        if (!dfn[v]) {
            vis[i] = true;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) min_val = min(min_val, edge[i].w);
        } else
            low[u] = min(low[u], dfn[v]);
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while (scanf("%d %d", &N, &M) && N + M) {
        init();
        up(i, 1, M) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        tarjan(1);
        int cnt = 0;
        up(i, 1, N) if (!dfn[i])++ cnt;
        if (cnt) {
            printf("0\n");
            continue;
        }
        if (min_val == 0) {
            printf("1\n");
            continue;
        }
        printf("%d\n", min_val == 10005 ? -1 : min_val);
    }

    return 0;
}