#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSteps(string s, string t) {
        vector<int> ss(26), tt(26);
        for (char ch : s) ss[ch - 'a']++;
        for (char ch : t) tt[ch - 'a']++;
        int cnt = 0;
        for (int i = 0; i < 26; i++) cnt += abs(ss[i] - tt[i]);
        return cnt;
    }
};