#include <bits/stdc++.h>
using namespace std;

class EulerianPath {
    vector<vector<int>> graph;
    vector<int> rpath;

   public:
    EulerianPath(vector<vector<int>> &g) : graph(g) { rpath.clear(); }

    void dfs(int u) {
        while (!graph[u].empty()) {
            int v = graph[u].back();
            graph[u].pop_back();
            dfs(v);
        }
        rpath.push_back(u);
    }

    vector<int> solve(int s) {
        dfs(s);
        return vector<int>(rpath.rbegin(), rpath.rend());
    }
};