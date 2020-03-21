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
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    up(case_num, 1, T) {
        cin >> N;
        init();
        for (int i = 1; i <= N; ++i)
            scanf("%lld %lld %lld %d", &b[i].x, &b[i].y, &b[i].r, &b[i].c);
        for (int i = 1; i <= N; ++i)
            for (int j = i + 1; j <= N; ++j) {
                ll dist = pow(b[i].x - b[j].x, 2) + pow(b[i].y - b[j].y, 2);
                if (dist <= pow(b[i].r, 2)) add_edge(i, j);
                if (dist <= pow(b[j].r, 2)) add_edge(j, i);
            }
        for (int i = 1; i <= N; ++i)
            if (!dfn[i]) tarjan(i);
        for (int i = 1; i <= N; ++i) link(j, i) {
                int v = edge[j].v;
                if (belong[i] != belong[v]) ++deg[belong[v]];
            }
        for (int i = 1; i <= scc; ++i)
            if (!deg[i]) ans += cost[i];
        cout << "Case #" << case_num << ": " << ans << '\n';
    }

    return 0;
}