#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(const string& a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (a[i] == a[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max({dp[i][j - 1], dp[i + 1][j]});
            }
        }
    }
    return dp[0][n - 1];
}