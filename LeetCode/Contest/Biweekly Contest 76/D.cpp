#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            sort(graph[i].begin(), graph[i].end(),
                 [&](int a, int b) { return scores[a] > scores[b]; });
        }
        int ans = -1;
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            int u1 = graph[u][0], v1 = graph[v][0];
            if (u1 != v && u1 != v1 && u != v1)
                ans = max(ans, scores[u] + scores[v] + scores[u1] + scores[v1]);
            if (u1 == v && v1 == u) {
                if (graph[u].size() > 1 && graph[v].size() > 1) {
                    u1 = graph[u][1], v1 = graph[v][1];
                }
            }
            if (graph[u].size() >= 2) {
                int u2 = graph[u][1];
                if (u2 != v && u2 != v1 && v1 != u) {
                    ans = max(ans,
                              scores[u] + scores[v] + scores[u2] + scores[v1]);
                }
            }
            if (graph[v].size() >= 2) {
                int v2 = graph[v][1];
                if (u1 != v && u1 != v2 && v2 != u) {
                    ans = max(ans,
                              scores[u] + scores[v] + scores[u1] + scores[v2]);
                }
            }

            if (graph[u].size() >= 3) {
                int u2 = graph[u][2];
                if (u2 != v && u2 != v1 && v1 != u) {
                    ans = max(ans,
                              scores[u] + scores[v] + scores[u2] + scores[v1]);
                }
            }
            if (graph[v].size() >= 3) {
                int v2 = graph[v][2];
                if (u1 != v && u1 != v2 && v2 != u) {
                    ans = max(ans,
                              scores[u] + scores[v] + scores[u1] + scores[v2]);
                }
            }
        }
        return ans;
    }
};