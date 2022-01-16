#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        for (int i : nums)
            if (i == 1) one++;
        int cur = 0;
        for (int i = 0; i < one; i++)
            if (nums[i] == 1) cur++;
        int ans = one - cur;
        for (int l = 1; l < n; l++) {
            int r = (l + one - 1) % n;
            if (nums[l - 1] == 1) cur--;
            if (nums[r] == 1) cur++;
            ans = min(ans, one - cur);
        }
        return ans;
    }
};