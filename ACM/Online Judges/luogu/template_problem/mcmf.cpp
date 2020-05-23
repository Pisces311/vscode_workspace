#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;
const int maxm = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct edge {
    int v, w, cost, next;
} edge[maxm];

int N, M, S, T, tot;
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

pair<int, int> min_cost_max_flow() {
    int min_cost = 0, max_flow = 0;
    while (spfa()) {
        int flow = inf;
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v)
            flow = min(edge[pre[i]].w, flow);
        max_flow += flow;
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v) {
            edge[pre[i]].w -= flow;
            edge[pre[i] ^ 1].w += flow;
            min_cost += edge[pre[i]].cost * flow;
        }
    }
    return make_pair(max_flow, min_cost);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> S >> T;
    init();
    while (M--) {
        int u, v, w, cost;
        cin >> u >> v >> w >> cost;
        add_edge(u, v, w, cost);
    }
    pair<int, int> ans = min_cost_max_flow();
    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}