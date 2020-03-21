#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 4e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxn << 1];

int T, n, m, u, v, w, tot;
int head[maxn], depth[maxn], f[maxn][30], dis[maxn];
bool vis[maxn];

inline void init() {
    tot = -1;
    mem(vis, false);
    mem(head, -1);
    mem(f, 0);
    mem(dis, 0);
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    depth[u] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        link(i, x) {
            int v = edge[i].v;
            if (!vis[v]) {
                dis[v] = dis[x] + edge[i].w;
                depth[v] = depth[x] + 1;
                vis[v] = 1;
                f[v][0] = x;
                up(j, 1, 16) f[v][j] = f[f[v][j - 1]][j - 1];
                q.push(v);
            }
        }
    }
}

int LCA(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    dn(i, 16, 0) if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return x;
    dn(i, 16, 0) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        init();
        up(i, 1, n - 1) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        bfs(1);
        up(i, 1, m) {
            scanf("%d %d", &u, &v);
            printf("%d\n", dis[u] + dis[v] - 2 * dis[LCA(u, v)]);
        }
    }

    return 0;
}