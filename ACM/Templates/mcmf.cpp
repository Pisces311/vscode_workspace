#include <bits/stdc++.h>
using namespace std;

class MCMF {
    const int inf = 0x3f3f3f3f;

    struct Edge {
        int v, w, cost, next;
        Edge(int v, int w, int cost, int next)
            : v(v), w(w), cost(cost), next(next) {}
    };

    vector<int> head, pre, dis;
    vector<bool> vis;
    vector<Edge> edges;

    bool spfa() {
        vis.assign(n, false);
        dis.assign(n, inf);
        pre.assign(n, -1);
        dis[S] = 0;
        queue<int> q;
        q.push(S);
        vis[S] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = head[u]; i != -1; i = edges[i].next) {
                auto& [v, w, cost, _] = edges[i];
                if (w) {
                    if (dis[u] + cost < dis[v]) {
                        dis[v] = dis[u] + cost;
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

   public:
    int S, T, n;

    MCMF(int S, int T, int n) : S(S), T(T), n(n) {
        head.assign(n, -1);
        edges.reserve(10005);
    }

    void add_edge(int u, int v, int w, int cost) {
        edges.emplace_back(v, w, cost, head[u]);
        head[u] = edges.size() - 1;
        edges.emplace_back(u, 0, -cost, head[v]);
        head[v] = edges.size() - 1;
    }

    pair<int, int> min_cost_max_flow() {
        int flow = 0, cost = 0;
        while (spfa()) {
            int cflow = inf;
            for (int i = T; i != S; i = edges[pre[i] ^ 1].v)
                cflow = min(edges[pre[i]].w, cflow);
            flow += cflow;
            for (int i = T; i != S; i = edges[pre[i] ^ 1].v) {
                edges[pre[i]].w -= cflow;
                edges[pre[i] ^ 1].w += cflow;
                cost += edges[pre[i]].cost * cflow;
            }
        }
        return make_pair(flow, cost);
    }
};