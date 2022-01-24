#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i : nums) {
            bool big = false, small = false;
            for (int j : nums)
                if (j < i) small = true;
            for (int j : nums)
                if (j > i) big = true;
            if (small && big) ans++;
        }
        return ans;
    }
};