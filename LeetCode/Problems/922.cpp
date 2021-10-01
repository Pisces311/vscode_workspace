#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd;
        for (int i : nums)
            if (i & 1)
                odd.push_back(i);
            else
                even.push_back(i);
        vector<int> ret;
        for (int i = 0; i < odd.size(); i++) {
            ret.push_back(even[i]);
            ret.push_back(odd[i]);
        }
        return ret;
    }
};