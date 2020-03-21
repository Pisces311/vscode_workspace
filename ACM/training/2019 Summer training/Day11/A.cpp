#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int v, pre, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int N;
int dis[maxn][maxn];
int depth[maxn], f[maxn][20], d[maxn];
vector<pii> g[maxn];
bool vis[maxn];
priority_queue<node> pq;

inline void init() {
    for (int i = 1; i <= N; ++i) g[i].clear();
    memset(f, 0, sizeof(f));
    memset(vis, false, sizeof(vis));
}

void prim() {
    pq.push({1, -1, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        if (t.pre != -1) {
            g[t.pre].push_back({t.v, t.w});
            g[t.v].push_back({t.pre, t.w});
        }
        for (int i = 1; i <= N; ++i)
            if (!vis[i]) pq.push({i, t.v, dis[t.v][i]});
    }
}

void bfs(int u) {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    depth[u] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < g[t].size(); ++i) {
            int v = g[t][i].first;
            if (!vis[v]) {
                d[v] = d[t] + g[t][i].second;
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

struct edge {
    int u, v, w;
    void show() { printf("%d %d %d\n", u, v, w); }
};

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int kas = 0;
    while (~scanf("%d", &N)) {
        printf(++kas == 1 ? "" : "\n");
        init();
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j) scanf("%d", &dis[i][j]);
        prim();
        edge last;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (g[i][j].first > i) {
                    last = {i, g[i][j].first, g[i][j].second};
                    last.show();
                }
            }
        }
        bfs(1);
        edge tmp = {0, 0, inf};
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (d[i] + d[j] - 2 * d[lca(i, j)] > dis[i][j]) {
                    if (dis[i][j] < tmp.w) {
                        tmp = {i, j, dis[i][j]};
                    }
                }
            }
        }
        if (tmp.w == inf)
            last.show();
        else
            tmp.show();
    }

    return 0;
}