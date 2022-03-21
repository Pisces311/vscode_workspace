#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countHillValley(vector<int>& nums) {
        vector<int> a;
        for (int i = 0; i < nums.size(); i++)
            if (i == 0 || nums[i] != nums[i - 1]) a.push_back(nums[i]);
        int ans = 0;
        for (int i = 1; i < a.size() - 1; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                ans++;
            else if (a[i - 1] > a[i] && a[i] < a[i + 1])
                ans++;
        }
        return ans;
    }
};