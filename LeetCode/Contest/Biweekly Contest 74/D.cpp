#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n, vector<int>(numCarpets + 1));
        if (floor[0] == '1') dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= numCarpets; j++) {
                dp[i][j] = dp[i - 1][j] + (floor[i] == '1');
                if (j > 0) {
                    if (i >= carpetLen)
                        dp[i][j] = min(dp[i][j], dp[i - carpetLen][j - 1]);
                    else
                        dp[i][j] = 0;
                }
            }
        }
        return dp[n - 1][numCarpets];
    }
};