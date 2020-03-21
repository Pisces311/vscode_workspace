#include <math.h>
#include <string.h>
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxn * maxn];

struct Bomb {
    ll x, y, r;
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
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    init();
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> b[i].x >> b[i].y >> b[i].r >> b[i].c;
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j) {
            ll dist = (b[i].x - b[j].x) * (b[i].x - b[j].x) +
                      (b[i].y - b[j].y) * (b[i].y - b[j].y);
            if (dist <= b[i].r * b[i].r) add_edge(i, j);
            if (dist <= b[j].r * b[j].r) add_edge(j, i);
        }
    for (int i = 1; i <= N; ++i)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= N; ++i)
        for (int j = head[i]; j != -1; j = edge[j].next) {
            int u = belong[i], v = belong[edge[j].v];
            if (u != v) ++deg[v];
        }
    for (int i = 1; i <= scc; ++i)
        if (!deg[i]) ans += cost[i];
    cout << ans << '\n';

    return 0;
}