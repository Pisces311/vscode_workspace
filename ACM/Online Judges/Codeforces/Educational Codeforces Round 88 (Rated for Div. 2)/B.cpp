#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, m, x, y;
int dp[105][1005];
char a[105][1005];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; ++i) cin >> (a[i] + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == '*')
                    dp[i][j] = dp[i][j - 1];
                else {
                    if (2 * x <= y)
                        dp[i][j] = dp[i][j - 1] + x;
                    else {
                        if (a[i][j + 1] == '.') {
                            dp[i][j + 1] = dp[i][j - 1] + y;
                            ++j;
                        } else
                            dp[i][j] = dp[i][j - 1] + x;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += dp[i][m];
        cout << ans << '\n';
    }

    return 0;
}