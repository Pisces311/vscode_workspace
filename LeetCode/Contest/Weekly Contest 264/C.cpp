#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int u, vector<vector<int>>& g, vector<int>& sz) {
        sz[u] = 1;
        for (int v : g[u]) {
            dfs(v, g, sz);
            sz[u] += sz[v];
        }
    }

   public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) g[parents[i]].push_back(i);
        }
        vector<int> sz(n);
        dfs(0, g, sz);
        vector<long long> score(n);
        for (int i = 0; i < n; i++) {
            long long p1 = 1, p2 = 1, p3 = 1;
            if (parents[i] != -1) p1 = n - sz[i];
            if (g[i].size() > 0) p2 = sz[g[i][0]];
            if (g[i].size() > 1) p3 = sz[g[i][1]];
            score[i] = p1 * p2 * p3;
        }
        return count(score.begin(), score.end(),
                     *max_element(score.begin(), score.end()));
    }
};