#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

struct EDGE {
    int u, v, w;
    bool operator<(const EDGE& a) const { return w < a.w; }
} edge[maxn * maxn];

struct node {
    int v, w;
};

int t, n, m, ans, sub_ans;
int parent[maxn], dis[maxn][maxn];
vector<node> g[maxn];
bool vis[maxn * maxn];

inline void init() {
    ans = 0;
    sub_ans = INT_MAX;
    up(i, 1, n) g[i].clear();
    mem(parent, -1);
    mem(vis, false);
}

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] >= 0; pos = parent[pos])
        ;
    while (pos != x) {
        int tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(int u, int v) {
    int tmp = parent[u] + parent[v];
    if (u < v) {
        parent[u] = tmp;
        parent[v] = u;
    } else {
        parent[u] = v;
        parent[v] = tmp;
    }
}

void dfs_mini(int s, int x, int pre, int maxs) {
    dis[s][x] = maxs;
    up(i, 0, (int)g[x].size() - 1) {
        int v = g[x][i].v;
        if (v != pre) dfs_mini(s, v, x, max(g[x][i].w, maxs));
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
        up(i, 1, m) scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge + 1, edge + m + 1);
        up(i, 1, m) {
            int x = find(edge[i].u), y = find(edge[i].v);
            if (x == y) continue;
            Union(x, y);
            ans += edge[i].w;
            g[edge[i].u].push_back({edge[i].v, edge[i].w});
            g[edge[i].v].push_back({edge[i].u, edge[i].w});
            vis[i] = true;
        }
        up(i, 1, n) dfs_mini(i, i, 0, 0);
        up(i, 1, m) if (!vis[i]) sub_ans =
            min(sub_ans, ans - dis[edge[i].u][edge[i].v] + edge[i].w);
        if (sub_ans != ans)
            printf("%d\n", ans);
        else
            printf("Not Unique!\n");
    }

    return 0;
}