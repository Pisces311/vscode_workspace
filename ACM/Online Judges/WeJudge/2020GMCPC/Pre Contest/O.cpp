#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int n;
ll a[maxn], dp[maxn][maxn], sum[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                dp[i][j] = 9e18;
                for (int k = i; k < j; ++k) {
                    ll cost = (sum[k] - sum[i - 1]) * (sum[j] - sum[k]);
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
                }
            }
        }
        cout << dp[1][n] << '\n';
    }

    return 0;
}