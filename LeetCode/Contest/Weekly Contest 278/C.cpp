#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

class Solution {
   public:
    ull hash(string s, vector<ull>& pow, int mod) {
        ull num = 0;
        for (int i = 0; i < s.size(); i++) {
            num += (pow[i] * (s[i] - 'a' + 1)) % mod;
            num %= mod;
        }
        return num;
    }

    string subStrHash(string s, int p, int mod, int k, int hashValue) {
        vector<ull> pow(k);
        pow[0] = 1;
        for (int i = 1; i < k; i++) pow[i] = (pow[i - 1] * p) % mod;
        int n = s.size();
        ull val = hash(s.substr(n - k), pow, mod);
        string ret = "";
        if (val == hashValue) ret = s.substr(n - k);
        for (int l = n - k - 1; l >= 0; l--) {
            int r = l + k - 1;
            val = (val - ((s[r + 1] - 'a' + 1) * pow[k - 1]) % mod + mod) % mod;
            val = (val * p + s[l] - 'a' + 1) % mod;
            if (val == hashValue) ret = s.substr(l, k);
        }
        return ret;
    }
};