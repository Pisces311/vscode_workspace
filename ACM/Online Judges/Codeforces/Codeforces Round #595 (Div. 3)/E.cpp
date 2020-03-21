#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n, c;
int a[maxn], b[maxn];
int dp[maxn][2];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n - 1; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) dp[i][0] = dp[i][1] = inf;
    dp[0][0] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int k = 0; k < 2; ++k) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][k] + a[i]);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][k] + b[i] + (!k ? c : 0));
        }
    for (int i = 0; i < n; ++i) cout << min(dp[i][0], dp[i][1]) << ' ';
    cout << '\n';

    return 0;
}