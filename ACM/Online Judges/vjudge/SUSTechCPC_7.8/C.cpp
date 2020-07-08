#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = (1 << 10) + 5;
constexpr int mod = 1e9 + 7;

int T, n, m;
int dp[maxn], cnt[maxn], ans[15];

inline void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 1 << n; ++i) cnt[i] = __builtin_popcount(i);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        while (m--) {
            char op;
            int x, y;
            cin >> op >> x >> y;
            int S = (1 << (x - 1)) | (1 << (y - 1));
            if (op == '+') {
                for (int i = 0; i < 1 << n; ++i)
                    if (!(i & S)) dp[i ^ S] = (dp[i ^ S] + dp[i]) % mod;
            } else {
                for (int i = 0; i < 1 << n; ++i)
                    if (!(i & S)) dp[i ^ S] = (dp[i ^ S] - dp[i] + mod) % mod;
            }
            memset(ans, 0, sizeof(ans));
            for (int i = 1; i < 1 << n; ++i)
                ans[cnt[i] / 2] = (ans[cnt[i] / 2] + dp[i]) % mod;
            for (int i = 1; i <= n / 2; ++i)
                cout << ans[i] << " \n"[i == n / 2];
        }
    }

    return 0;
}