#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int calculate(string s) {
        int ans = 0;
        vector<int> signs(2, 1);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i < s.size() && s[i] >= '0')
                    num = 10 * num - '0' + s[i++];
                ans += signs.back() * num;
                signs.pop_back();
                i--;
            } else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return ans;
    }
};