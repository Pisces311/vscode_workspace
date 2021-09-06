#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> ret;
        vector<vector<bool>> vis(n, vector<bool>(m));
        int r1, r2, c1, c2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    while (c2 < m - 1 && land[r2][c2 + 1] == 1) c2++;
                    while (r2 < n - 1 && land[r2 + 1][c2] == 1) r2++;
                    ret.push_back({r1, c1, r2, c2});
                    for (int k = r1; k <= r2; k++) {
                        for (int l = c1; l <= c2; l++) {
                            vis[k][l] = true;
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution a;
    vector<vector<int>> v = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    auto ans = a.findFarmland(v);
    for (auto i : ans) {
        for (auto j : i) cout << j << ' ';
        cout << endl;
    }
    return 0;
}