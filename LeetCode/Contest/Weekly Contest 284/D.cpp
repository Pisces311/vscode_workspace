#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    int id;
    ll d;
    bool operator<(const node& a) const { return d > a.d; }
};

class Solution {
   public:
    const ll inf = LLONG_MAX;

    vector<ll> dijkstra(int n, vector<vector<vector<int>>>& graph, int src) {
        vector<ll> dis(n, inf);
        priority_queue<node> pq;
        pq.push({src, 0});
        dis[src] = 0;
        while (!pq.empty()) {
            auto [u, d] = pq.top();
            pq.pop();
            if (d > dis[u]) continue;
            for (vector<int>& edge : graph[u]) {
                int v = edge[0], w = edge[1];
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({v, dis[v]});
                }
            }
        }
        return dis;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        vector<vector<vector<int>>> graph(n), Rgraph(n);
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            Rgraph[v].push_back({u, w});
        }
        vector<ll> dis1 = dijkstra(n, graph, src1);
        vector<ll> dis2 = dijkstra(n, graph, src2);
        vector<ll> dis3 = dijkstra(n, Rgraph, dest);
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            if (dis1[i] != inf && dis2[i] != inf && dis3[i] != inf)
                ans = min(ans, dis1[i] + dis2[i] + dis3[i]);
        }
        return ans == inf ? -1 : ans;
    }
};