#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> chs(26);
        for (char ch : s) chs[ch - 'a']++;
        string ans = "";
        int cont = 0;
        for (int i = 0; i < s.size(); i++) {
            int prev = ans.size();
            for (int j = 25; j >= 0; j--) {
                if (chs[j]) {
                    char cur = 'a' + j;
                    if (ans.empty() || ans.back() != cur ||
                        (ans.back() == cur && cont < repeatLimit)) {
                        ans += cur;
                        chs[j]--;
                        if (ans.size() == 1)
                            cont = 1;
                        else if (ans[ans.size() - 2] == ans.back())
                            cont++;
                        else
                            cont = 1;
                        break;
                    }
                }
            }
            if (prev == ans.size()) break;
        }
        return ans;
    }
};