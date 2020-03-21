#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e4 + 5;
const int maxm = 25e4 + 5;

struct Edge {
    int u, v, next;
} edge[maxm];

int T, n, m, k, v, tot, order, scc;
int cx[maxn], cy[maxn], head[maxm], dfn[maxn], low[maxn], in[maxn],
    belong[maxn], ans[maxm];
bool vis[maxn];
stack<int> stk;

inline void init() {
    order = scc = 0;
    tot = -1;
    mem(head, -1);
    mem(dfn, 0);
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

int line(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!vis[v]) {
            vis[v] = true;
            if (cy[v] == -1 || line(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int sum = 0;
    mem(cx, -1);
    mem(cy, -1);
    up(i, 1, n) {
        if (cx[i] == -1) {
            mem(vis, false);
            sum += line(i);
        }
    }
    return sum;
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
        } while (t != u);
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    up(case_num, 1, T) {
        scanf("%d %d", &n, &m);
        init();
        up(i, 1, n) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &v);
                add_edge(i, v + n);
            }
        }
        hungary();
        int all = n + m;
        up(i, 1, n) if (cx[i] == -1) {
            ++all;
            cx[i] = all;
            cy[all] = i;
            up(j, 1, n) add_edge(j, all);
        }
        up(i, n + 1, n + m) if (cy[i] == -1) {
            ++all;
            cx[all] = i;
            cy[i] = all;
            up(j, n + 1, n + m) add_edge(all, j);
        }
        up(i, 1, all) if (cx[i] != -1) add_edge(cx[i], i);
        up(i, 1, all) if (!dfn[i]) tarjan(i);
        printf("Case #%d:\n", case_num);
        up(i, 1, n) {
            int cnt = 0;
            for (int j = head[i]; j != -1; j = edge[j].next) {
                int v = edge[j].v;
                if (belong[i] == belong[v]) {
                    if (v - n <= m) ans[cnt++] = v - n;
                }
            }
            sort(ans, ans + cnt);
            printf("%d", cnt);
            up(j, 0, cnt - 1) printf(" %d", ans[j]);
            printf("\n");
        }
    }

    return 0;
}