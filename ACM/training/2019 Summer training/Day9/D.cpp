#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const int maxm = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct coor {
    int x, y;
} c[maxn];

struct Edge {
    int u, v;
    double w;
} edge[maxm << 1];

int N, M, tot;
double in[maxn];
int pre[maxn], id[maxn], vis[maxn];

inline void init() { tot = 0; }

inline void add_edge(int u, int v, double w) { edge[++tot] = {u, v, w}; }

inline double get_dist(int u, int v) {
    return hypot(1.0 * (c[u].x - c[v].x), 1.0 * (c[u].y - c[v].y));
}

double zhuliu(int rt) {
    double ans = 0;
    while (true) {
        for (int i = 1; i <= N; ++i) in[i] = inf;
        for (int i = 1; i <= tot; ++i) {
            int u = edge[i].u, v = edge[i].v;
            double w = edge[i].w;
            if (u == v)
                continue;
            else if (in[v] > w) {
                pre[v] = u;
                in[v] = w;
            }
        }
        for (int i = 1; i <= N; ++i)
            if (i != rt && in[i] == inf) return -1;
        int cnt = 0;
        memset(id, 0, sizeof(id));
        memset(vis, 0, sizeof(vis));
        in[rt] = 0;
        for (int i = 1; i <= N; ++i) {
            ans += in[i];
            int v = i;
            while (!id[v] && v != rt && vis[v] != i) {
                vis[v] = i;
                v = pre[v];
            }
            if (v != rt && !id[v]) {
                id[v] = ++cnt;
                for (int j = pre[v]; j != v; j = pre[j]) id[j] = cnt;
            }
        }
        if (!cnt) break;
        for (int i = 1; i <= N; ++i)
            if (!id[i]) id[i] = ++cnt;
        for (int i = 1; i <= M; ++i) {
            int x = edge[i].u, y = edge[i].v;
            edge[i].u = id[x];
            edge[i].v = id[y];
            if (id[x] != id[y]) edge[i].w -= in[y];
        }
        N = cnt;
        rt = id[rt];
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M)) {
        init();
        for (int i = 1; i <= N; ++i) scanf("%d %d", &c[i].x, &c[i].y);
        for (int i = 1; i <= M; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u == v) continue;
            add_edge(u, v, get_dist(u, v));
        }
        double ans = zhuliu(1);
        if (ans == -1)
            printf("poor snoopy\n");
        else
            printf("%.2f\n", ans);
    }

    return 0;
}