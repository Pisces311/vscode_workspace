#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int maxm = 3e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, next;
} edge[maxm << 1];

int n, m, tot, u, v, ans;
int head[maxn], deg[maxn], dis[maxn];

inline void init() {
    ans = 0;
    tot = -1;
    mem(head, -1);
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

int dfs(int x) {
    if (!dis[x]) {
        dis[x] = 1;
        link(i, x) {
            int v = edge[i].v;
            if (deg[v] > deg[x]) {
                dis[x] = max(dfs(v) + 1, dis[x]);
            }
        }
    }
    return dis[x];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    init();
    up(i, 1, m) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
        ++deg[u];
        ++deg[v];
    }
    up(i, 0, n - 1) if (!dis[i]) ans = max(ans, dfs(i));
    printf("%d\n", ans);

    return 0;
}