#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
ll dp[50];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 35; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    while (cin >> n) cout << dp[n] << '\n';

    return 0;
}