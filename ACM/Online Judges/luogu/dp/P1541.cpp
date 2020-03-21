#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e1 + 5;

int dp[maxn][maxn][maxn][maxn], num[351], g[5], n, m, x;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> num[i];
    dp[0][0][0][0] = num[1];
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        ++g[x];
    }
    for (int a = 0; a <= g[1]; ++a)
        for (int b = 0; b <= g[2]; ++b)
            for (int c = 0; c <= g[3]; ++c)
                for (int d = 0; d <= g[4]; ++d) {
                    int r = 1 + a + b * 2 + c * 3 + d * 4;
                    if (a != 0)
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a - 1][b][c][d] + num[r]);
                    if (b != 0)
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a][b - 1][c][d] + num[r]);
                    if (c != 0)
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a][b][c - 1][d] + num[r]);
                    if (d != 0)
                        dp[a][b][c][d] =
                            max(dp[a][b][c][d], dp[a][b][c][d - 1] + num[r]);
                }
    cout << dp[g[1]][g[2]][g[3]][g[4]] << '\n';

    return 0;
}