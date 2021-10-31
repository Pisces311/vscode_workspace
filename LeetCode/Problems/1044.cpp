#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

// Seed options: 31, 131, 1313, 13131, 131313...
class BKDRHash {
    ull seed;

   public:
    BKDRHash(ull seed) : seed(seed) {}
    ull get(string str, int l, int r) {
        ull hash = 0;
        for (int i = l; i <= r; ++i) hash = hash * seed + str[i];
        return (hash & 0xFFFFFFFFFFFFFFFF);
    }
};

class Solution {
    vector<ull> pow;

    string dup(string& s, int len) {
        BKDRHash hasher(131);
        set<ull> exist;
        int l = 0, r = len - 1;
        ull number = hasher.get(s, l, r);
        exist.insert(number);
        for (int i = 1, j = len; j < s.size(); i++, j++) {
            number = (number - s[i - 1] * pow[len - 1]) * 131 + s[j];
            if (exist.find(number) != exist.end())
                return s.substr(i, len);
            else
                exist.insert(number);
        }
        return "";
    }

   public:
    string longestDupSubstring(string s) {
        pow.resize(s.size());
        pow[0] = 1;
        for (int i = 1; i < s.size(); i++) pow[i] = pow[i - 1] * 131;
        int l = 1, r = s.size() - 1;
        string ans = "";
        while (l <= r) {
            int mid = (l + r) / 2;
            string cur = dup(s, mid);
            if (cur != "") {
                l = mid + 1;
                ans = cur;
            } else
                r = mid - 1;
        }
        return ans;
    }
};