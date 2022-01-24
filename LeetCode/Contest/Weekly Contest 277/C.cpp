#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            bool lonely = true;
            if (i != 0 && nums[i] - nums[i - 1] <= 1) lonely = false;
            if (i != n - 1 && nums[i + 1] - nums[i] <= 1) lonely = false;
            if (lonely) ret.push_back(nums[i]);
        }
        return ret;
    }
};