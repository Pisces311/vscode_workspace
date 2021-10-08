#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> find(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) return {i, j};
            }
        }
        return {};
    }

   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<int> st = find(grid);
        q.push(st);
        vis[st[0]][st[1]] = true;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            vector<int> u = q.front();
            q.pop();
            for (int i = 0; i < dir.size(); i++) {
                int x = u[0] + dir[i][0], y = u[1] + dir[i][1];
                if (0 <= x && x < n && 0 <= y && y < m && grid[x][y]) {
                    if (!vis[x][y]) {
                        q.push({x, y});
                        vis[x][y] = true;
                    }
                } else
                    ans++;
            }
        }
        return ans;
    }
};