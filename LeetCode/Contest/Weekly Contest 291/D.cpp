#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;

   public:
    ll appealSum(string s) {
        int n = s.size();
        ll tot = 0;
        for (int i = 1; i <= n; i++) {
            tot += 1ll * i * (n - i + 1);
        }
        vector<vector<int>> a(26);
        for (int i = 0; i < n; i++) {
            int id = s[i] - 'a';
            a[id].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < a[i].size(); j++) {
                int l = a[i][j - 1] + 1, r = n - a[i][j];
                tot -= 1ll * l * r;
            }
        }
        return tot;
    }
};