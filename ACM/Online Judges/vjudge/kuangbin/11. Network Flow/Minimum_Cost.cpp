#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 5e1 + 5;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int N, M, K;
int need[maxn][maxn], supply[maxn][maxn];
int cost[maxn][maxn][maxn];

struct edge {
    int v, w, cost, next;
} edge[maxm];

int S, T, tot;
int head[maxn], dis[maxn], pre[maxn];
bool vis[maxn];

void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w, int cost) {
    edge[++tot] = {v, w, cost, head[u]};
    head[u] = tot;
    edge[++tot] = {u, 0, -cost, head[v]};
    head[v] = tot;
}

bool spfa() {
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    dis[S] = 0;
    queue<int> q;
    q.push(S);
    vis[S] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (edge[i].w) {
                int v = edge[i].v;
                if (dis[u] + edge[i].cost < dis[v]) {
                    dis[v] = dis[u] + edge[i].cost;
                    pre[v] = i;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    return pre[T] != -1;
}

int min_cost_max_flow() {
    int ret = 0;
    while (spfa()) {
        int flow = inf;
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v)
            flow = min(edge[pre[i]].w, flow);
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v) {
            edge[pre[i]].w -= flow;
            edge[pre[i] ^ 1].w += flow;
            ret += edge[pre[i]].cost * flow;
        }
    }
    return ret;
}

int solve() {
    int tot_cost = 0;
    for (int i = 1; i <= K; ++i) {
        init();
        int x = 0, y = 0;
        for (int j = 1; j <= M; ++j) x += supply[j][i];
        for (int j = 1; j <= N; ++j) y += need[j][i];
        if (y > x) return -1;
        for (int j = 1; j <= N; ++j) add_edge(S, j, need[j][i], 0);
        for (int j = 1; j <= M; ++j) add_edge(N + j, T, supply[j][i], 0);
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= M; ++k) {
                add_edge(j, N + k, inf, cost[i][j][k]);
            }
        }
        int tot = 0;
        for (int j = 1; j <= N; ++j) tot += need[j][i];
        tot_cost += min_cost_max_flow();
    }
    return tot_cost;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M >> K, N + M + K) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= K; ++j) {
                cin >> need[i][j];
            }
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= K; ++j) {
                cin >> supply[i][j];
            }
        }
        for (int i = 1; i <= K; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int k = 1; k <= M; ++k) {
                    cin >> cost[i][j][k];
                }
            }
        }
        S = 0, T = N + M + 1;
        cout << solve() << '\n';
    }

    return 0;
}