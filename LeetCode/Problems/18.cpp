#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tgt = target - nums[i] - nums[j];
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum < tgt)
                        l++;
                    else if (sum > tgt)
                        r--;
                    else {
                        vector<int> triplet = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(triplet);
                        while (l < r && nums[l] == triplet[2]) l++;
                        while (l < r && nums[r] == triplet[3]) r--;
                    }
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};
