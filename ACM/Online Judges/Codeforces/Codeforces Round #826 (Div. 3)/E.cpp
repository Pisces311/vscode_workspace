#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        if (dp[i - 1]) {
            if (i + a[i] <= n) dp[i + a[i]] = true;
        }
        if (i - a[i] >= 1 && dp[i - a[i] - 1]) dp[i] = true;
    }
    return dp[n] ? "YES" : "NO";
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}