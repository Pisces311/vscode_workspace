#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
   public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime,
                          int numLaps) {
        int n = tires.size();
        vector<vector<int>> tire(n, vector<int>(20, INT_MAX));
        for (int i = 0; i < n; i++) {
            tire[i][1] = tires[i][0];
            for (int j = 2; j < 20; j++) {
                if (1ll * tire[i][j - 1] * tires[i][1] >= INT_MAX) break;
                tire[i][j] = tire[i][j - 1] * tires[i][1];
            }
            for (int j = 2; j < 20; j++) {
                if (1ll * tire[i][j - 1] + tire[i][j] >= INT_MAX) break;
                tire[i][j] += tire[i][j - 1];
            }
        }

        vector<int> dp(numLaps + 1, INT_MAX);
        for (int i = 0; i < n; i++) {
            dp[1] = min(dp[1], tires[i][0]);
        }
        for (int x = 1; x <= numLaps; x++) {
            if (x < 20) {
                for (int i = 0; i < n; i++) {
                    dp[x] = min(dp[x], tire[i][x]);
                }
            }
            for (int j = x - 1; j > 0 && j >= x - 18; j--) {
                dp[x] = min(dp[x], dp[j] + changeTime + dp[x - j]);
            }
        }

        return dp[numLaps];
    }
};