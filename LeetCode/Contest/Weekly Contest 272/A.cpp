#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string firstPalindrome(vector<string>& words) {
        for (string& str : words) {
            if (str == string(str.rbegin(), str.rend())) return str;
        }
        return "";
    }
};