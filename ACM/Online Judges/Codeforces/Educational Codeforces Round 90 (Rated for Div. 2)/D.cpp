#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n;
ll a[maxn], dp[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll sum = 0;
        for (int i = 1; i <= n; i += 2) sum += a[i];
        int top = 0;
        for (int i = 2; i <= n; i += 2) dp[++top] = a[i] - a[i - 1];
        for (int i = 1; i <= top; ++i) dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ll inc1 = max(0ll, *max_element(dp + 1, dp + top + 1));
        top = 0;
        for (int i = 3; i <= n; i += 2) dp[++top] = a[i - 1] - a[i];
        for (int i = 1; i <= top; ++i) dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ll inc2 = max(0ll, *max_element(dp + 1, dp + top + 1));
        cout << sum + max(inc1, inc2) << '\n';
    }

    return 0;
}