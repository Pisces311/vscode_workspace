#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

class Solution {
   public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pii>> g(n);
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vector<int> dist(n, maxMoves + 1);
        dist[0] = 0;
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node]) continue;
            ans++;
            for (pii pair : g[node]) {
                int v = pair.first, w = pair.second;
                if (dist[node] + w + 1 > maxMoves) continue;
                if (dist[node] + w + 1 < dist[v]) {
                    dist[v] = dist[node] + w + 1;
                    pq.push({dist[v], v});
                }
            }
        }
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int used = 0;
            if (dist[u] <= maxMoves) used += maxMoves - dist[u];
            if (dist[v] <= maxMoves) used += maxMoves - dist[v];
            ans += min(w, used);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {
        {1, 2, 5}, {0, 3, 3}, {1, 3, 2}, {2, 3, 4}, {0, 4, 1}};
    cout << sol.reachableNodes(v, 7, 5) << endl;
    return 0;
}