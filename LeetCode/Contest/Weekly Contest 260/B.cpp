#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
   public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.front().size();
        if (n == 1) return 0;
        vector<ll> pre(n), post(n);
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + grid[1][i - 1];
        for (int i = n - 2; i >= 0; i--) post[i] = post[i + 1] + grid[0][i + 1];
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, max(pre[i], post[i]));
        }
        return ans;
    }
};