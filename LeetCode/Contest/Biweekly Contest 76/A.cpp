#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findClosestNumber(vector<int>& nums) {
        int dif = INT_MAX, ans = INT_MIN;
        for (int num : nums) {
            if (abs(num) < dif) {
                dif = abs(num);
                ans = num;
            } else if (abs(num) == dif) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};