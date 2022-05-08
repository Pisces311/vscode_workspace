#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char ans = '0' - 1;
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
                if (num[i] > ans) ans = num[i];
            }
        }
        if (ans == '0' - 1)
            return "";
        else
            return string(3, ans);
    }
};