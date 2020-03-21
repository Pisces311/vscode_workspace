#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, n;
int len[maxn];
ll a[maxn];
ll dp[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) dp[i] = 0;
        ll ma = 0, sum = 0;
        int length = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            if (dp[i - 1] + a[i] > a[i]) {
                dp[i] = dp[i - 1] + a[i];
                len[i] = len[i - 1] + 1;
            } else {
                dp[i] = a[i];
                len[i] = 1;
            }
            if (dp[i] > ma) {
                ma = dp[i];
                length = len[i];
            }
        }
        if (ma < sum)
            cout << "YES\n";
        else if (ma == sum && length == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}