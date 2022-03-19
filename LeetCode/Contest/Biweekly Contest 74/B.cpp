#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++) {
            l[i] = l[i - 1];
            if (text[i - 1] == pattern[0]) l[i]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            r[i] = r[i + 1];
            if (text[i] == pattern[1]) r[i]++;
        }
        long long base = 0;
        for (int i = 0; i <= n; i++) {
            if (text[i] == pattern[0]) {
                base += r[i + 1];
            }
        }
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            long long cur = max(l[i], r[i]);
            ans = max(ans, base + cur);
        }
        return ans;
    }
};