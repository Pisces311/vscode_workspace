#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e2 + 5;
constexpr int inf = 0x3f3f3f3f;

int n, k;
char a[maxn], b[maxn];
int dp[maxn][maxn][maxn];  // dp[i][j][k]表示前i位，用了j步，有k个b[1]

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> (a + 1) >> (b + 1);
    if (b[1] == b[2]) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += (a[i] == b[1]);
        cnt = min(cnt + k, n);
        cout << cnt * (cnt - 1) / 2 << '\n';
    } else {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j) fill(dp[i][j], dp[i][j] + n + 1, -inf);
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                    dp[i][j + (a[i] != b[1])][k + 1] =
                        max(dp[i][j + (a[i] != b[1])][k + 1], dp[i - 1][j][k]);
                    dp[i][j + (a[i] != b[2])][k] =
                        max(dp[i][j + (a[i] != b[2])][k], dp[i - 1][j][k] + k);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                ans = max(ans, *max_element(dp[i][j], dp[i][j] + n + 1));
        cout << ans << '\n';
    }

    return 0;
}