#include <bits/stdc++.h>
using namespace std;

// index starts from 1
class LCA {
   public:
    int n, m, root;
    vector<int> depth;
    vector<vector<int>> g, f;

    LCA(int n, int r) : n(n), m(log2(n) + 1), root(r) {
        depth.assign(n + 1, 0);
        g.assign(n + 1, vector<int>());
        f.assign(n + 1, vector<int>(m + 1));
    }

    void addEdge(int u, int v) { g[u].push_back(v); }

    void init() {
        vector<bool> vis(n + 1);
        queue<int> q;
        q.push(root);
        vis[root] = true;
        depth[root] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    depth[v] = depth[u] + 1;
                    vis[v] = true;
                    f[v][0] = u;
                    for (int j = 1; j <= m; ++j)
                        f[v][j] = f[f[v][j - 1]][j - 1];
                    q.push(v);
                }
            }
        }
    }

    int lca(int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);
        for (int i = m; i >= 0; i--)
            if (depth[f[y][i]] >= depth[x]) y = f[y][i];
        if (x == y) return x;
        for (int i = m; i >= 0; i--)
            if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
        return f[x][0];
    }
};