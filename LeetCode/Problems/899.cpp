#include <bits/stdc++.h>
using namespace std;

class Solution {
    int least_rotation(string s) {
        int n = s.size();
        int k = 0, i = 0, j = 1;
        while (k < n && i < n && j < n) {
            if (s[(i + k) % n] == s[(j + k) % n]) {
                ++k;
            } else {
                s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
                if (i == j) ++i;
                k = 0;
            }
        }
        return min(i, j);
    }

   public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        int p = least_rotation(s);
        return s.substr(p) + s.substr(0, p);
    }
};