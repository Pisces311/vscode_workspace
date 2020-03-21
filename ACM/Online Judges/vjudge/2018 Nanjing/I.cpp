#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[1000005];

int n, m, k, S, T, P, tot;
int head[maxn], depth[maxn], cur[maxn];

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
    edge[++tot] = {v, u, 0, head[v]};
    head[v] = tot;
}

int dfs(int u, int flow) {
    if (u == T) return flow;
    for (int& i = cur[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if ((depth[v] == depth[u] + 1) && (edge[i].w != 0)) {
            int di = dfs(v, min(flow, edge[i].w));
            if (di > 0) {
                edge[i].w -= di;
                edge[i ^ 1].w += di;
                return di;
            }
        }
    }
    return 0;
}

bool bfs() {
    queue<int> q;
    memset(depth, 0, sizeof(depth));
    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = head[f]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if ((depth[v] == 0) && edge[i].w > 0) {
                depth[v] = depth[f] + 1;
                q.push(v);
            }
        }
    }
    if (depth[T] > 0) return true;
    return false;
}

//注意后面对当前弧数组的初始化应包括所有点
int dinic() {
    int ans = 0;
    while (bfs()) {
        for (int i = S; i <= P; ++i) cur[i] = head[i];
        while (int d = dfs(S, inf)) ans += d;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    init();
    S = 0, T = n + m + 1, P = n + m + 2;
    for (int i = 1; i <= n; ++i) add_edge(S, i, 1);
    for (int i = 1; i <= m; ++i) add_edge(n + i, T, 1);
    for (int i = 1, num, v; i <= n; ++i) {
        cin >> num;
        while (num--) {
            cin >> v;
            add_edge(i, n + v, 1);
        }
    }
    add_edge(S, P, k);
    for (int i = 1; i <= n; ++i) add_edge(P, i, 1);
    cout << dinic() << '\n';

    return 0;
}