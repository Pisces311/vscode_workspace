#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int inf = 0x3f3f3f3f;

int n, ans;
int a[maxn], dp[maxn][65];

inline void init() {
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= 60; ++j) dp[i][j] = -inf;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i] += 30;
    init();
    dp[1][a[1]] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 60; ++j) {
            if (dp[i - 1][j] != -inf) {
                if (j > a[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] - 30);
                else
                    dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][j] + j - 30);
            }
        }
        dp[i][a[i]] = max(dp[i][a[i]], 0);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= 60; ++j) ans = max(ans, dp[i][j]);
    cout << ans << '\n';

    return 0;
}
