#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    int bfs(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, -1));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dis[0][0] = 0;
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int i = 0; i < 4; i++) {
                int vx = x + dx[i], vy = y + dy[i];
                if (0 <= vx && vx < n && 0 <= vy && vy < m) {
                    int w = (grid[vx][vy] == 1);
                    if (dis[vx][vy] == -1) {
                        dis[vx][vy] = dis[x][y] + w;
                        if (w) {
                            dq.push_back({vx, vy});
                        } else {
                            dq.push_front({vx, vy});
                        }
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }

   public:
    int minimumObstacles(vector<vector<int>>& grid) { return bfs(grid); }
};