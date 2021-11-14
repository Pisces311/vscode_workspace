#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long ans;
    vector<vector<vector<int>>> g;
    vector<int> vis;

    void dfs(int u, int d, long long val, vector<int>& values, int maxTime) {
        if (d > maxTime) return;
        vis[u]++;
        if (u == 0) ans = max(ans, val);
        for (vector<int>& i : g[u]) {
            if (!vis[i[0]])
                dfs(i[0], d + i[1], val + values[i[0]], values, maxTime);
            else
                dfs(i[0], d + i[1], val, values, maxTime);
        }
        vis[u]--;
    }

   public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                           int maxTime) {
        ans = 0;
        int n = values.size();
        g.resize(n);
        for (int i = 0; i < n; i++) g[i].clear();
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vis.resize(n);
        fill(vis.begin(), vis.end(), 0);
        dfs(0, 0, values[0], values, maxTime);
        return ans;
    }
};

int main() {
    vector<int> values = {5, 10, 15, 20};
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}};
    Solution sol;
    cout << sol.maximalPathQuality(values, edges, 30) << endl;
    return 0;
}