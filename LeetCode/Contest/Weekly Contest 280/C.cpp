#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long minimumRemoval(vector<int>& beans) {
        vector<int> num(100001);
        for (int i : beans) num[i]++;
        long long ans = accumulate(beans.begin(), beans.end(), 0ll);
        long long all = ans;
        int after = beans.size();
        for (int i = 0; i <= 100000; i++) {
            ans = min(ans, all - 1ll * after * i);
            after -= num[i];
        }
        return ans;
    }
};