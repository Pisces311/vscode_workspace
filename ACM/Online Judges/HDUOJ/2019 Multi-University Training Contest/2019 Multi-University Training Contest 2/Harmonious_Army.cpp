#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e4 + 5e2 + 5;
const int maxm = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[20 * maxm];

int n, m, S, T, tot;
int head[maxn], depth[maxn], cur[maxn];

inline void init() {
    S = 0, T = 2e4 + 5e2 + 1;
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

ll dinic() {
    ll ans = 0;
    while (bfs()) {
        for (int i = S; i <= T; ++i) cur[i] = head[i];
        while (int d = dfs(S, inf)) ans += d;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &m)) {
        init();
        int num = 500;
        ll sum = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v, a, b, c;
            scanf("%d %d %d %d %d", &u, &v, &a, &b, &c);
            sum += a + c;
            add_edge(S, u, a / 4);
            add_edge(S, v, a / 4);
            add_edge(u, T, c / 3);
            add_edge(v, T, c / 3);
            add_edge(S, ++num, a / 2);
            add_edge(num, u, inf);
            add_edge(num, v, inf);
            add_edge(u, ++num, inf);
            add_edge(v, num, inf);
            add_edge(num, T, c / 3);
        }
        printf("%lld\n", sum - dinic());
    }

    return 0;
}