#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;
constexpr int maxm = 3e3 + 5;
constexpr int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm];

// cur数组进行当前弧优化，记录之前访问到哪条边
int n, m, S, T, tot;
int d[maxn];
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

//对残量网络进行分层，若汇点depth不为0则存在增广路
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
    return depth[T] > 0;
}

//注意后面对当前弧数组的初始化应包括所有点
int dinic() {
    int ans = 0;
    while (bfs()) {
        for (int i = S; i <= T; ++i) cur[i] = head[i];
        while (int d = dfs(S, inf)) ans += d;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        init();
        S = 0, T = 2 * n + 1;
        for (int i = 1; i <= n; ++i) {
            cin >> d[i];
            add_edge(S, i, d[i]);
            add_edge(i + n, T, d[i]);
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v + n, 1);
            add_edge(v, u + n, 1);
        }
        if (dinic() == accumulate(d + 1, d + n + 1, 0))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}