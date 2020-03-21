#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxn * maxn];

struct Bomb {
    ll r, x, y;
    int c;
} b[maxn];

int T, N;
int order, scc, tot;
ll ans;
int head[maxn], deg[maxn], cost[maxn];
int dfn[maxn], low[maxn], belong[maxn], in[maxn];
stack<int> stk;

inline void init() {
    tot = -1;
    order = scc = 0;
    ans = 0;
    mem(dfn, 0);
    mem(head, -1);
    mem(deg, 0);
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
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
        int t, mi = inf;
        do {
            t = stk.top();
            stk.pop();
            in[t] = false;
            belong[t] = scc;
            mi = min(b[t].c, mi);
        } while (t != u);
        cost[scc] = mi;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    up(case_num, 1, T) {
        scanf("%d", &N);
        init();
        up(i, 1, N)
            scanf("%lld %lld %lld %d", &b[i].x, &b[i].y, &b[i].r, &b[i].c);
        up(i, 1, N) up(j, i + 1, N) {
            ll dist = pow(b[i].x - b[j].x, 2) + pow(b[i].y - b[j].y, 2);
            if (dist <= pow(b[i].r, 2)) add_edge(i, j);
            if (dist <= pow(b[j].r, 2)) add_edge(j, i);
        }
        up(i, 1, N) if (!dfn[i]) tarjan(i);
        up(i, 1, N) link(j, i) {
            int v = edge[j].v;
            if (belong[i] != belong[v]) ++deg[belong[v]];
        }
        up(i, 1, scc) if (!deg[i]) ans += cost[i];
        printf("Case #%d: %lld\n", case_num, ans);
    }

    return 0;
}