#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans(n + 5);
        vector<int> zero(n + 5), one(n + 5);
        for (int i = 0; i < n; i++) {
            zero[i] = (nums[i] == 0);
            if (i > 0) zero[i] += zero[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            one[i] = (nums[i] == 1);
            if (i != n - 1) one[i] += one[i + 1];
        }
        for (int i = 0; i <= n; i++) {
            int cnt = 0;
            if (i != 0) cnt += zero[i - 1];
            if (i != n) cnt += one[i];
            ans[cnt].push_back(i);
        }
        for (int i = n; i >= 0; i--) {
            if (!ans[i].empty()) return ans[i];
        }
        return {};
    }
};