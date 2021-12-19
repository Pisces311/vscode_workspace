#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<long long> seg;
        int n = prices.size();
        for (int i = 0; i < n;) {
            int j = i;
            long long len = 1;
            while (j + 1 < n && prices[j + 1] - prices[j] == -1) {
                j++;
                len++;
            }
            seg.push_back(len);
            i = j + 1;
        }
        long long ans = 0;
        for (long long i : seg) ans += (1 + i) * i / 2;
        return ans;
    }
};