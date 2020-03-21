#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;
const int maxm = 5e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm];

struct node {
    int v, w;
};

int n, m, T, tot;
int head[maxn], pre[maxn][maxn], dp[maxn][maxn];
bool used[maxn][maxn];

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

void bfs() {
    queue<node> q;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            dp[i][j] = T + 1;
            pre[i][j] = 0;
        }
    q.push({1, 1});
    used[1][1] = true;
    dp[1][1] = 0;
    while (!q.empty()) {
        node f = q.front();
        q.pop();
        int u = f.v, v = f.w;
        used[u][v] = false;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int x = edge[i].v, y = edge[i].w;
            if (dp[u][v] + y > T) continue;
            if (dp[x][v + 1] > dp[u][v] + y) {
                dp[x][v + 1] = dp[u][v] + y;
                pre[x][v + 1] = u;
                if (used[x][v + 1]) continue;
                used[x][v + 1] = true;
                q.push({x, v + 1});
            }
        }
    }
}

void init(int x, int y) {
    if (pre[x][y] != 0) init(pre[x][y], y - 1);
    if (x == n)
        printf("%d\n", x);
    else
        printf("%d ", x);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &T);
    init();
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    bfs();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[n][i] <= T) ans = i;
    printf("%d\n", ans);
    init(n, ans);

    return 0;
}