#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            vector<int>& q = questions[i];
            int id = i + q[1] + 1;
            if (id < n) {
                dp[i] = max(dp[i + 1], dp[id] + q[0]);
            } else if (i != n - 1)
                dp[i] = max(dp[i + 1], 1ll * q[0]);
            else
                dp[i] = q[0];
        }
        return dp[0];
    }
};