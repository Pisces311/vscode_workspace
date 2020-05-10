#include <limits.h>

#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int n;
int a[maxn], level[maxn];
int dp[maxn][maxn];

int up() {
    sort(level + 1, level + n + 1);
    for (int i = 1; i <= n; ++i) dp[1][i] = abs(a[1] - level[i]);
    for (int i = 2; i <= n; ++i) {
        int Min = INT_MAX;
        for (int j = 1; j <= n; ++j) {
            Min = min(Min, dp[i - 1][j]);
            dp[i][j] = Min + abs(a[i] - level[j]);
        }
    }
    return *min_element(dp[n] + 1, dp[n] + n + 1);
}

int down() {
    reverse(level + 1, level + n + 1);
    for (int i = 2; i <= n; ++i) {
        int Min = INT_MAX;
        for (int j = n; j >= 1; --j) {
            Min = min(Min, dp[i - 1][j]);
            dp[i][j] = Min + abs(a[i] - level[j]);
        }
    }
    return *min_element(dp[n] + 1, dp[n] + n + 1);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) level[i] = a[i];
    int ret1 = up(), ret2 = down();
    cout << min(ret1, ret2) << '\n';

    return 0;
}