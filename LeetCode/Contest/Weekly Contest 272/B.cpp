#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (j < spaces.size()) {
                if (i == spaces[j]) {
                    ans += ' ';
                    j++;
                }
            }
            ans += s[i];
        }
        return ans;
    }
};