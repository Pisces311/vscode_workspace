#include <bits/stdc++.h>
using namespace std;

// Edges must have positive weights
vector<int> Dijkstra(vector<vector<vector<int>>>& g, int s) {
    using pii = pair<int, int>;

    int n = g.size();
    vector<int> dis(n, 0x3f3f3f3f);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, s);
    dis[s] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u]) continue;
        for (vector<int>& edge : g[u]) {
            int v = edge[0], w = edge[1];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        }
    }
    return dis;
}