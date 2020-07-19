#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, a, b;
int dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 1000; ++i) dp[1][i] = dp[i][1] = i;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 2; j <= 1000; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (__gcd(i, j) == 1);
        }
    }
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }

    return 0;
}