#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2) {
            if (nums[i] != nums[i - 1]) return false;
        }
        return true;
    }
};