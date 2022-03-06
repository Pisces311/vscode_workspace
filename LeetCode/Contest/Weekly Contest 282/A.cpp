#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool prefix(string a, string b) {
        if (a.size() < b.size()) return false;
        for (int i = 0; i < b.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (string& str : words) {
            if (prefix(str, pref)) cnt++;
        }
        return cnt;
    }
};