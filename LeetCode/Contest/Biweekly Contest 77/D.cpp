#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    vector<vector<int>> g, dis;

    bool valid(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && g[x][y] != 2;
    }

    bool check(int mid) {
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<tuple<int, int, int>> q;
        vis[0][0] = true;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (valid(nx, ny) && !vis[nx][ny]) {
                    if (nx == n - 1 && ny == m - 1 &&
                        dis[nx][ny] >= mid + d + 1)
                        return true;
                    if (dis[nx][ny] > mid + d + 1) {
                        vis[nx][ny] = true;
                        q.push({nx, ny, d + 1});
                    }
                }
            }
        }
        return false;
    }

   public:
    int maximumMinutes(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        dis.assign(n, vector<int>(m, INT_MAX));

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (valid(nx, ny) && dis[nx][ny] == INT_MAX) {
                    dis[nx][ny] = d + 1;
                    q.push({nx, ny, d + 1});
                }
            }
        }

        int l = 0, r = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};