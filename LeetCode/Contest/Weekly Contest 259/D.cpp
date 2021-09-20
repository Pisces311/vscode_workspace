#include <bits/stdc++.h>
using namespace std;

class Solution {
    string ans;

   public:
    int cnt(string s, string seq) {
        if (seq.empty()) return s.size();
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (seq[j] == s[i]) {
                j++;
                if (j == seq.size()) {
                    j = 0;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void rec(string s, string seq, int k) {
        if (cnt(s, seq) < k) return;
        if (seq.size() >= ans.size() && seq > ans) ans = seq;
        for (char c = 'a'; c <= 'z'; c++) rec(s, seq + c, k);
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        rec(s, "", k);
        return ans;
    }
};