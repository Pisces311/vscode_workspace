#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3;
constexpr int maxm = 1e4;
constexpr int inf = 0x3f3f3f3f;

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