#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        for (int i = 0; i < n; i += k) {
            string tmp = "";
            for (int j = i; j < i + k; j++) {
                if (j < n)
                    tmp += s[j];
                else
                    tmp += fill;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};