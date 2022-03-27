#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        // dp[i][j]: the maximum value we can get picking j coins from the first
        // i piles
        vector<vector<int>> dp(n, vector<int>(k + 1));
        for (int i = 1; i <= min(k, (int)piles[0].size()); i++) {
            dp[0][i] = dp[0][i - 1] + piles[0][i - 1];
        }

        // the total number of coins of the first (i - 1) piles
        int tot = piles[0].size();
        for (int i = 1; i < n; i++) {
            int pileSize = piles[i].size();

            // presum of the i-th pile
            vector<int> presum(k + 1);
            for (int j = 1; j <= min(k, pileSize); j++) {
                presum[j] = presum[j - 1] + piles[i][j - 1];
            }

            // pick j coins from the first i piles, j should be no greater than
            // the sum of the first i piles
            for (int j = 0; j <= min(k, tot + pileSize); j++) {
                // pick l coins from the first (i - 1) piles
                // these j coins consist of two parts:
                // 1. l coins from the previous piles, dp[i-1][j]
                // 2. j - l coins from the current (i-th) pile, presum[j-l]
                for (int l = max(0, j - pileSize); l <= min({j, k, tot}); l++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][l] + presum[j - l]);
                }
            }

            // update tot
            tot += pileSize;
        }
        return dp[n - 1][k];
    }
};