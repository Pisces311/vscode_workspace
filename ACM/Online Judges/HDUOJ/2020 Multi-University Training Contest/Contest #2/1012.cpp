#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n, m, q;
int nxt[maxn][27], dp[25][25];
char a[maxn], b[25];

int LCS(int l, int r) {
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = l - 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (dp[i - 1][j] < r)
                dp[i][j + 1] =
                    min(dp[i][j + 1], nxt[dp[i - 1][j] + 1][b[i] - 'a']);
        }
    }
    for (int i = m; i >= 1; --i)
        for (int j = i; j <= m; ++j)
            if (dp[j][i] <= r) return i;
    return 0;
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
        cin >> (a + 1) >> (b + 1);
        n = strlen(a + 1), m = strlen(b + 1);
        for (int i = 0; i < 26; ++i) nxt[n + 1][i] = n + 1;
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j < 26; ++j) nxt[i][j] = nxt[i + 1][j];
            nxt[i][a[i] - 'a'] = i;
        }
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << r - l + 1 + m - 2 * LCS(l, r) << '\n';
        }
    }

    return 0;
}