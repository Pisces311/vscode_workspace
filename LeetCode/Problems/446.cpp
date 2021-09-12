#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        vector<map<ll, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll dif = (ll)nums[i] - (ll)nums[j];
                int sum = 0;
                if (dp[j].find(dif) != dp[j].end()) sum = dp[j][dif];
                dp[i][dif] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};