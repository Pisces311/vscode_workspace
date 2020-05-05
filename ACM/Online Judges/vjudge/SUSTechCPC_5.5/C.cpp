#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e1 + 5;

int n;
int a[maxn][maxn];
int val[maxn][1 << 16], dp[maxn][1 << 16];
vector<int> valid;

inline void init() {
    valid.clear();
    memset(val, 0, sizeof(val));
    memset(dp, 0, sizeof(dp));
}

int cal(int i, int j) {
    int ret = 0;
    for (int k = 1; k <= 20; ++k) {
        if ((1 << (k - 1)) & j) ret += a[i][n - k + 1];
    }
    return ret;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        assert(n <= 16);
        init();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) cin >> a[i][j];
        for (int i = 1; i < (1 << n); ++i)
            if (!(i & (i >> 1))) valid.push_back(i);
        for (int i = 1; i <= n; ++i) {
            for (int j : valid) {
                val[i][j] = cal(i, j);
            }
        }
        for (int i : valid) dp[1][i] = val[1][i];
        for (int i = 2; i <= n; ++i) {
            for (int j : valid) {
                for (int k : valid) {
                    if (!(j & k))
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + val[i][j]);
                }
            }
        }
        cout << *max_element(dp[n] + 1, dp[n] + (1 << n)) << '\n';
    }

    return 0;
}