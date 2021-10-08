#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tot = mean * (rolls.size() + n);
        int ntot = tot - accumulate(rolls.begin(), rolls.end(), 0);
        if (ntot > n * 6) return {};
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            int rest = n - 1 - i;
            ret[i] = 6;
            ntot -= 6;
            while (ntot < rest) {
                ret[i]--;
                ntot++;
                if (!ret[i]) return {};
            }
        }
        return ret;
    }
};