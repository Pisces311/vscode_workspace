#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxn << 1];

int t, N, tot;
bool vis[maxn];
int head[maxn], depth[maxn], f[maxn][20], dis[maxn];

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(f, 0, sizeof(f));
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
        int t = q.front();
        q.pop();
        for (int i = head[t]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (!vis[v]) {
                dis[v] = dis[t] + edge[i].w;
                depth[v] = depth[t] + 1;
                vis[v] = 1;
                f[v][0] = t;
                for (int j = 1; j <= 16; ++j) f[v][j] = f[f[v][j - 1]][j - 1];
                q.push(v);
            }
        }
    }
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    for (int i = 16; i >= 0; --i)
        if (depth[f[y][i]] >= depth[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 16; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

inline int solve(int x, int y, int k) {
    int fa = lca(x, y), s = x;
    int len1 = min(depth[x] - depth[fa], k - 1),
        len2 = depth[x] + depth[y] - 2 * depth[fa] - k + 1;
    for (int i = 16; i >= 0; i--)
        if (len1 >= (1 << i)) len1 -= 1 << i, x = f[x][i];
    if (depth[s] - depth[fa] >= k - 1) return x;
    for (int i = 16; i >= 0; i--)
        if (len2 >= (1 << i)) len2 -= 1 << i, y = f[y][i];
    return y;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        init();
        for (int i = 1; i < N; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        bfs(1);
        char op[10];
        while (true) {
            scanf("%s", op + 1);
            if (op[2] == 'O') break;
            int a, b, k;
            scanf("%d %d", &a, &b);
            if (op[2] == 'I')
                printf("%d\n", dis[a] + dis[b] - 2 * dis[lca(a, b)]);
            else {
                scanf("%d", &k);
                printf("%d\n", solve(a, b, k));
            }
        }
    }

    return 0;
}