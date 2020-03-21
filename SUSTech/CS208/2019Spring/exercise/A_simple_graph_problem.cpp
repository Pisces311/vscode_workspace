#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e3 + 5;
const int maxm = 3e3 + 5;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int N, M, S, T, tot, u, v, val;
int head[maxm], depth[maxn], cur[maxn];

//数据初始化
inline void init() {
    tot = -1;
    S = 0;
    T = N + 1;
    mem(head, -1);
}

//链式前向星加边
inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
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
    mem(depth, 0);
    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        link(i, f) {
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

// dinic算法求最大流
int dinic() {
    int ans = 0;
    while (bfs()) {
        up(i, S, T) cur[i] = head[i];  // dinic算法的当前弧优化
        while (int d = dfs(S, INT_MAX)) ans += d;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    init();
    up(i, 1, N) {
        scanf("%d", &val);
        if (val) {  //若点权为1则与源点连边
            add_edge(S, i, 1);
            add_edge(i, S, 0);
        } else {  //否则与汇点连边
            add_edge(i, T, 1);
            add_edge(T, i, 0);
        }
    }
    up(i, 1, M) {  //点对之间连双向边
        scanf("%d %d", &u, &v);
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    printf("%d\n", dinic());  //输出最大流即为答案

    return 0;
}