#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); i++) {
            if (i & 1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), [](int a, int b) { return a > b; });
        vector<int> ret;
        for (int i = 0; i < max(even.size(), odd.size()); i++) {
            if (i < even.size()) ret.push_back(even[i]);
            if (i < odd.size()) ret.push_back(odd[i]);
        }
        return ret;
    }
};