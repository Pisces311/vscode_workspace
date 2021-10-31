#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for (int i : nums) cnt[i]++;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (!cnt[j]) j++;
            nums[i] = j;
            cnt[j]--;
        }
    }
};