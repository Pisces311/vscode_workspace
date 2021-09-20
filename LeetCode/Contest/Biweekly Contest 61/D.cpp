#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int ans = n;
        for (int l = 0, r = 0; l < nums.size(); l++) {
            while (r < nums.size() - 1 && nums[r + 1] - nums[l] <= n - 1) r++;
            ans = min(ans, n - (r - l + 1));
        }
        return ans;
    }
};