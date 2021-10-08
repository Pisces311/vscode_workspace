#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3);
        for (int a : stones) cnt[a % 3]++;
        if (cnt[0] % 2 == 0) return cnt[1] > 0 && cnt[2] > 0;
        return abs(cnt[1] - cnt[2]) > 2;
    }
};