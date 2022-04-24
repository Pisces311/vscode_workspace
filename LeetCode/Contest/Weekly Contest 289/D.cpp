#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<vector<int>> &edges, int u, string &s, vector<int> &d1,
             vector<int> &d2, int &ans) {
        for (int v : edges[u]) {
            dfs(edges, v, s, d1, d2, ans);
            if (s[u] == s[v]) continue;
            int len = d1[v] + 1;
            if (len >= d1[u]) {
                d2[u] = d1[u];
                d1[u] = len;
            } else if (len >= d2[u]) {
                d2[u] = len;
            }
        }
        ans = max(ans, d1[u] + d2[u] + 1);
    }

    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<int> d1(n), d2(n);
        vector<vector<int>> edges(n);
        for (int u = 0; u < parent.size(); u++) {
            int fa = parent[u];
            if (fa != -1) {
                edges[fa].push_back(u);
            }
        }
        int ans = 0;
        dfs(edges, 0, s, d1, d2, ans);
        return ans;
    }
};