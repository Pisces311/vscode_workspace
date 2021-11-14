#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char, int> d1, d2;
        for (char ch : word1) d1[ch]++;
        for (char ch : word2) d2[ch]++;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (abs(d1[ch] - d2[ch]) > 3) return false;
        }
        return true;
    }
};