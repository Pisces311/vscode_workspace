#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

struct Edge {
    int u, v, next;
} edge[2 * maxn];

int t, n, m, tot, u, v, cnt;
int head[maxn], col[maxn];

inline void init() {
    cnt = tot = 0;
    up(i, 1, n) {
        head[i] = -1;
        col[i] = 0;
    }
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

void dfs(int u) {
    link(i, u) {
        int v = edge[i].v;
        if (!col[v]) {
            col[v] = col[u] == 1 ? 2 : 1;
            dfs(v);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init();
        up(i, 1, m) {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        col[1] = 1;
        dfs(1);
        up(i, 1, n) cnt += (col[i] == 1);
        if (cnt * 2 <= n) {
            printf("%d\n", cnt);
            up(i, 1, n) if (col[i] == 1) printf("%d ", i);
        } else {
            printf("%d\n", n - cnt);
            up(i, 1, n) if (col[i] == 2) printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}