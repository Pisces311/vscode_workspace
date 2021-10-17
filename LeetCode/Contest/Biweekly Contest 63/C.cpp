#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> g(n);
        for (vector<int> e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        queue<vector<int>> q;
        q.push({0, 0});
        vector<int> dis(n, n + 1);
        while (!q.empty()) {
            vector<int> vec = q.front();
            q.pop();
            int u = vec[0], d = vec[1];
            if (dis[u] != n + 1) continue;
            dis[u] = d;
            for (int v : g[u]) q.push({v, d + 1});
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int last_sent = 0, eta = 2 * dis[i];
            if (patience[i] < eta) {
                last_sent = (eta - 1) / patience[i] * patience[i];
            }
            ans = max(ans, last_sent + eta + 1);
        }
        return ans;
    }
};