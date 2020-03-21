#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e2 + 5;

int n;
int a[maxn];
int dp[maxn][maxn];

int check(int x) { return x > 2 * n ? 1 : x; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i + l - 1 <= 2 * n; ++i) {
            int j = i + l - 1;
            for (int k = i + 1; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k][j] +
                                             a[i] * a[k] * a[check(j + 1)]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i][i + n - 1]);
    cout << ans << '\n';

    return 0;
}