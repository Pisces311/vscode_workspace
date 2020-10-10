#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int r, n;
int x[maxn], y[maxn], t[maxn];
int dp[maxn], Max[maxn];

int dis(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i] >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (t[i] - t[j] >= 2 * r) {
                dp[i] = max(dp[i], Max[j] + 1);
                break;
            } else if ((t[i] - t[j] >= dis(i, j) && dp[j]) ||
                       (!j && x[i] + y[i] - 2 <= t[i]))
                dp[i] = max(dp[i], dp[j] + 1);
        }
        Max[i] = max(Max[i - 1], dp[i]);
    }
    cout << Max[n] << '\n';

    return 0;
}