#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumDifference(vector<int> &nums) {
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1), right(n + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            int l = 0, r = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    l += nums[i];
                    r += nums[i + n];
                }
            }
            int sz = __builtin_popcount(mask);
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        for (vector<int> &i : right) sort(i.begin(), i.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = INT_MAX;
        for (int sz = 0; sz < n; sz++) {
            for (int a : left[sz]) {
                int b = (sum - 2 * a) / 2, rsz = n - sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(), b);
                if (itr != v.end()) res = min(res, abs(sum - 2 * (a + (*itr))));
                if (itr != v.begin()) {
                    itr--;
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                }
            }
        }
        return res;
    }
};