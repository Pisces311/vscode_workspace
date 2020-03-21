#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int n, M, T;
int a[maxn][2];
int dp[205][205];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> M >> T;
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = M; j >= a[i][0]; --j) {
            for (int k = T; k >= a[i][1]; --k) {
                dp[j][k] = max(dp[j][k], dp[j - a[i][0]][k - a[i][1]] + 1);
                ans = max(ans, dp[j][k]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}