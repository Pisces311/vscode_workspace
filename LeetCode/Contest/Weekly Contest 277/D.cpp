#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(int mask, vector<vector<int>>& statements) {
        int n = statements.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << i)) && !(mask & (1 << j)) &&
                    statements[i][j] == 1)
                    return false;
                if ((mask & (1 << i)) && (mask & (1 << j)) &&
                    statements[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (check(mask, statements)) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        return ans;
    }
};