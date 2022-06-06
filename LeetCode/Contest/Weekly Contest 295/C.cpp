#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int totalSteps(vector<int>& A) {
        int n = A.size();
        stack<int> stk;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && A[i] > A[stk.top()]) {
                dp[i] = max(dp[i] + 1, dp[stk.top()]);
                stk.pop();
            }
            stk.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};