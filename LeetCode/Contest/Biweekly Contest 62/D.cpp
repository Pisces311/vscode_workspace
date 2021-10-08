#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;

   public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> pre(n), suf(n);
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
            suf[n - 1 - i] = suf[n - i] + nums[n - 1 - i];
        }
        map<ll, ll> left, right;
        for (int i = 0; i < n - 1; i++) right[pre[i] - suf[i + 1]]++;
        ll ans = right[0];
        for (int i = 0; i < n; i++) {
            ll diff = k - nums[i];
            ll curr = left[diff] + right[-diff];
            ans = max(ans, curr);
            if (i < n - 1) {
                ll dd = pre[i] - suf[i + 1];
                left[dd]++;
                right[dd]--;
            }
        }
        return ans;
    }
};