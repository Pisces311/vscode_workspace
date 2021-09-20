#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
    int bsearch(vector<vector<int>>& rides, int target) {
        int l = 0, r = rides.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (rides[mid][0] >= target) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }

   public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<ll> dp(n + 1);
        for (int i = rides.size() - 1; i >= 0; i--) {
            dp[i] =
                max(1ll * (rides[i][1] + rides[i][2] - rides[i][0]), dp[i + 1]);
            int p = bsearch(rides, rides[i][1]);
            if (p != -1)
                dp[i] =
                    max(dp[i], dp[p] + rides[i][1] + rides[i][2] - rides[i][0]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};