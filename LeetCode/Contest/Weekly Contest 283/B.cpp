#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 1ll * (1 + k) * k / 2;
        long long cur = k;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                ans += nums[i];
            else if (nums[i] <= cur) {
                ans += cur + 1;
                cur++;
            } else
                ans += nums[i];
        }
        for (int i : nums) ans -= i;
        return ans;
    }
};