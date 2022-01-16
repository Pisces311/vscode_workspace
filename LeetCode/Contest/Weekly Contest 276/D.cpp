#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0L);
        int k = 0;
        while (batteries[m - 1 - k] > sum / (n - k))
            sum -= batteries[m - 1 - k++];
        return sum / (n - k);
    }
};