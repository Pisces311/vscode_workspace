#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;
    ll mod = 1e9 + 7;

   public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        pressedKeys = '#' + pressedKeys;
        ll ans = 1;
        vector<ll> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = 2;
            if (pressedKeys[i] == '7' || pressedKeys[i] == '9') num = 3;
            for (int j = 0; j <= num; j++) {
                if (i - j < 1) continue;
                if (pressedKeys[i - j] != pressedKeys[i]) break;
                dp[i] = (dp[i] + dp[i - j - 1]) % mod;
            }
        }
        return dp[n];
    }
};