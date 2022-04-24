#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    using pii = pair<int, int>;

    pii get(int num) {
        int cnt2 = 0, cnt5 = 0;
        while (num % 2 == 0) {
            num /= 2;
            cnt2++;
        }
        while (num % 5 == 0) {
            num /= 5;
            cnt5++;
        }
        return make_pair(cnt2, cnt5);
    }

    pii sum(pii a, pii b) {
        return make_pair(a.first + b.first, a.second + b.second);
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pii>> presum(n, vector<pii>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    presum[i][j] = get(grid[i][j]);
                } else {
                    presum[i][j] = sum(presum[i][j - 1], get(grid[i][j]));
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            pii cur = make_pair(0, 0);
            for (int i = 0; i < n; i++) {
                pii l = presum[i][j];
                pii r = presum[i][m - 1];
                if (j > 0) {
                    r.first -= presum[i][j - 1].first;
                    r.second -= presum[i][j - 1].second;
                }
                int tmp = max(min(cur.first + l.first, cur.second + l.second),
                              min(cur.first + r.first, cur.second + r.second));
                ans = max(ans, tmp);
                cur = sum(cur, get(grid[i][j]));
            }
        }
        for (int j = 0; j < m; j++) {
            pii cur = make_pair(0, 0);
            for (int i = n - 1; i >= 0; i--) {
                pii l = presum[i][j];
                pii r = presum[i][m - 1];
                if (j > 0) {
                    r.first -= presum[i][j - 1].first;
                    r.second -= presum[i][j - 1].second;
                }
                int tmp = max(min(cur.first + l.first, cur.second + l.second),
                              min(cur.first + r.first, cur.second + r.second));
                ans = max(ans, tmp);
                cur = sum(cur, get(grid[i][j]));
            }
        }
        return ans;
    }
};