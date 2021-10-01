#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int e = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (s != nums.size() && nums[s] == target)
            return {s, e};
        else
            return {-1, -1};
    }
};