#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int tar = target - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (abs(target - nums[i] - sum) < abs(target - ans))
                    ans = nums[i] + sum;
                if (sum < tar)
                    l++;
                else if (sum > tar)
                    r--;
                else
                    break;
            }
        }
        return ans;
    }
};
