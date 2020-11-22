#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e2 + 5;
constexpr int inf = 0x3f3f3f3f;

char s[maxn];
int cnt[maxn], dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> (s + 1);
        int n = strlen(s + 1), m = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != s[i - 1])
                cnt[++m] = 1;
            else
                cnt[m]++;
        }
        for (int i = 1; i <= m; ++i) dp[i][i] = 3 - cnt[i];
        for (int len = 2; len <= m; ++len) {
            for (int l = 1; l + len - 1 <= m; ++l) {
                int r = l + len - 1;
                dp[l][r] = inf;
                for (int k = l; k < r; ++k)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                if (len & 1) {
                    dp[l][r] =
                        min(dp[l][r], dp[l + 1][r - 1] + (cnt[l] + cnt[r] < 3));
                    if (cnt[l] + cnt[r] < 4)
                        for (int k = l + 2; k < r; k += 2)
                            if (cnt[k] == 1)
                                dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] +
                                                             dp[k + 1][r - 1]);
                }
            }
        }
        cout << "Case #" << cas << ": " << dp[1][m] << '\n';
    }

    return 0;
}