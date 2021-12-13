#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxPower(string s) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (all_of(s.begin() + i, s.begin() + j,
                           [&](char ch) { return ch == s[i]; }))
                    cnt = max(cnt, j - i);
            }
        }
        return cnt;
    }
};