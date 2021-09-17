#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> dp(arr.size());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1]) dp[i] = 2;
            if (i > 1) {
                if ((arr[i] > arr[i - 1] && arr[i - 1] < arr[i - 2]) ||
                    (arr[i] < arr[i - 1] && arr[i - 1] > arr[i - 2]))
                    dp[i] = max(dp[i], dp[i - 1] + 1);
            }
        }
        return max(1, *max_element(dp.begin(), dp.end()));
    }
};