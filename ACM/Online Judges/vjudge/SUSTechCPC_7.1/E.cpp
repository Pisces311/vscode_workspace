#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int T, n;
char s[maxn];
ll dp[maxn][2], a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> s;
        int n = strlen(s);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (s[0] == '0')
            dp[0][0] = 0;
        else if (s[0] == '1')
            dp[0][1] = a[0];
        else {
            dp[0][0] = 0;
            dp[0][1] = a[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (s[i] != '?' && s[i] != j + '0') continue;
                if (s[i - 1] == '0')
                    dp[i][j] = dp[i - 1][0] + a[i] * (s[i - 1] != j + '0');
                else if (s[i - 1] == '1')
                    dp[i][j] = dp[i - 1][1] + a[i] * (s[i - 1] != j + '0');
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j ^ 1] + a[i]);
            }
        }
        cout << "Case #" << cas << ": " << max(dp[n - 1][0], dp[n - 1][1])
             << '\n';
    }

    return 0;
}