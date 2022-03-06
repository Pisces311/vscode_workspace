#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> cellsInRange(string s) {
        char c1 = s[0], c2 = s[3];
        int d1 = s[1] - '0', d2 = s[4] - '0';
        vector<string> ret;
        for (char ch = c1; ch <= c2; ch++) {
            for (int i = d1; i <= d2; i++) {
                string digit = to_string(i);
                ret.push_back(ch + digit);
            }
        }
        return ret;
    }
};