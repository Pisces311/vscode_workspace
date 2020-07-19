#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n;
ll a[maxn], dif[maxn], sum[maxn], dp[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i < n; ++i) dif[i] = a[i + 1] - a[i];
        for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + dif[i];
        dp[4] = sum[3] * 2;
        dp[6] = sum[5] * 2;
        dp[8] = dp[4] + (sum[7] - sum[4]) * 2;
        for (int i = 10; i <= n; i += 2) {
            dp[i] = min(dp[i - 4] + (sum[i - 1] - sum[i - 4]) * 2,
                        dp[i - 6] + (sum[i - 1] - sum[i - 6]) * 2);
        }
        cout << dp[n] << '\n';
    }

    return 0;
}