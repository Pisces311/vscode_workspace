#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;
        vector<int> indexes;
        int n = s.length(), num = words.size();
        int len = words.front().length();
        unordered_map<string, int> seen;
        for (int i = 0; i < n - num * len + 1; i++) {
            seen.clear();
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word]) break;
                } else
                    break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};