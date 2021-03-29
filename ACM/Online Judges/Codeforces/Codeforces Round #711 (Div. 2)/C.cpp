#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;
constexpr int mod = 1e9 + 7;

int t, n, k;
ll dp[maxn][maxn], sum[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll ans = 1;
        for (int i = 1; i <= k - 1; ++i) {
            if (i == 1) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = 1;
                    sum[i][j] = j;
                    ans = (ans + dp[i][j]) % mod;
                }
                continue;
            }
            for (int j = 1; j <= n; ++j) {
                if (i & 1) {
                    dp[i][j] = sum[i - 1][n] - sum[i - 1][j] + mod;
                } else {
                    dp[i][j] = sum[i - 1][j - 1];
                }
                dp[i][j] %= mod;
                sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
                ans = (ans + dp[i][j]) % mod;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}