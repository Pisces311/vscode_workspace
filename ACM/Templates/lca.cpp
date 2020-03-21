#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxm];

bool vis[maxn];
int head[maxn], depth[maxn], f[maxn][20];

//获得倍增数组f和深度数组depth
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