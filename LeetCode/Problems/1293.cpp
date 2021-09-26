#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            vector<int> u = q.front();
            q.pop();
            if (vis[u[0]][u[1]] >= u[3]) continue;
            vis[u[0]][u[1]] = u[3];
            if (u[0] == n - 1 && u[1] == m - 1) return u[2];
            for (vector<int>& d : dir) {
                int vx = u[0] + d[0], vy = u[1] + d[1];
                if (0 <= vx && vx < n && 0 <= vy && vy < m) {
                    if (grid[vx][vy] == 1 && u[3]) {
                        q.push({vx, vy, u[2] + 1, u[3] - 1});
                    } else if (!grid[vx][vy]) {
                        q.push({vx, vy, u[2] + 1, u[3]});
                    }
                }
            }
        }
        return -1;
    }
};