#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

class Solution {
   public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<vector<ll>> dp(n, vector<ll>(2));
        dp[0][0] = 0, dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i][0] + (dp[i][0] - dp[nextVisit[i]][0] + mod) % mod + 1;
            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
        return dp[n - 1][0];
    }
};

int main() {
    Solution a;
    vector<int> v = {0, 1, 2, 0};
    cout << a.firstDayBeenInAllRooms(v) << endl;
    return 0;
}