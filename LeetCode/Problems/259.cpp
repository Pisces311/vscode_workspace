#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int Max = target - nums[i] - nums[j];
                ans += lower_bound(nums.begin() + j + 1, nums.end(), Max) - nums.begin() - j - 1;
            }
        }
        return ans;
    }
};