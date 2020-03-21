#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxf = 5e3 + 5;
const int maxr = 1e4 + 5;

struct EDGE {
    int u, v, next;
} edge[maxr];

int F, R, tot, u, v, w, order, scc;
int head[maxr], low[maxf], dfn[maxf], in[maxf], belong[maxf];
int deg[maxf];
bool vis[maxr];
stack<int> stk;

inline void init() {
    order = scc = 0;
    tot = -1;
    mem(head, -1);
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
        if (vis[i] || vis[i ^ 1]) continue;
        int v = edge[i].v;
        if (!dfn[v]) {
            vis[i] = true;
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

    scanf("%d %d", &F, &R);
    init();
    up(i, 1, R) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    tarjan(1);
    up(i, 1, F) {
        for (int j = head[i]; j != -1; j = edge[j].next) {
            int u = edge[j].u, v = edge[j].v;
            if (belong[u] != belong[v]) {
                ++deg[belong[u]];
                ++deg[belong[v]];
            }
        }
    }
    int ans = 0;
    up(i, 1, scc) if (deg[i] == 2)++ ans;
    printf("%d\n", (ans + 1) / 2);

    return 0;
}