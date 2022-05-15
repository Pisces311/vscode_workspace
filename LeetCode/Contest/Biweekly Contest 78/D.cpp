#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestVariance(string s) {
        int ans = 0;
        set<char> st(s.begin(), s.end());
        for (char a : st)
            for (char b : st) {
                int cur = 0, has_b = 0, first_b = 0;
                for (auto ch : s) {
                    cur = max(cur, -1) + (ch == a);
                    if (ch == b) {
                        has_b = true;
                        if (first_b && cur >= 0)
                            first_b = false;
                        else if (--cur < 0)
                            first_b = true;
                    }
                    ans = max(ans, has_b ? cur : 0);
                }
            }
        return ans;
    }
};