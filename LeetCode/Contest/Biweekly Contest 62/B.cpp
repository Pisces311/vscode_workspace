#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] + nums[j] == target) ans++;
            }
        }
        return ans;
    }
};