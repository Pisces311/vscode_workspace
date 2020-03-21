#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    ll val[5];
} a[maxn];

int n;
ll dp[maxn][32];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= 4; ++j) cin >> a[i].val[j];
    int bit = 1 << 6;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < bit; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= 4; ++k) {
                int tmp = 1 << k;
                if ((j & tmp) == 0) continue;
                int val = a[i].val[k];
                dp[i][j] = max(dp[i][j], dp[i - 1][j - tmp] + val);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i][31]);
    cout << ans << endl;

    return 0;
}