#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> vis(
            n, vector<vector<bool>>(m, vector<bool>(200)));
        queue<tuple<int, int, int>> q;

        if (grid[0][0] == ')') return false;
        vis[0][0][1] = true;
        q.push({0, 0, 1});
        while (!q.empty()) {
            auto [x, y, l] = q.front();
            q.pop();
            if (x == n - 1 && y == m - 1 && !l) return true;
            if (x + 1 < n) {
                if (grid[x + 1][y] == '(') {
                    if (!vis[x + 1][y][l + 1]) {
                        vis[x + 1][y][l + 1] = true;
                        q.push({x + 1, y, l + 1});
                    }
                } else {
                    if (l && !vis[x + 1][y][l - 1]) {
                        vis[x + 1][y][l - 1] = true;
                        q.push({x + 1, y, l - 1});
                    }
                }
            }
            if (y + 1 < m) {
                if (grid[x][y + 1] == '(') {
                    if (!vis[x][y + 1][l + 1]) {
                        vis[x][y + 1][l + 1] = true;
                        q.push({x, y + 1, l + 1});
                    }
                } else {
                    if (l && !vis[x][y + 1][l - 1]) {
                        vis[x][y + 1][l - 1] = true;
                        q.push({x, y + 1, l - 1});
                    }
                }
            }
        }
        return false;
    }
};