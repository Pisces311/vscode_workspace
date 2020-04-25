#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int a[maxn][5], dp[maxn][5];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 4; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 4; ++j) {
            for (int k = 0; k <= 4; ++k) {
                if (j == 0 || j != k)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }
    cout << *max_element(dp[n], dp[n] + 5) << '\n';

    return 0;
}