#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countMaxOrSubsets(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int OR = 0;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) OR |= nums[i];
            m[OR]++;
        }
        return m.rbegin()->second;
    }
};