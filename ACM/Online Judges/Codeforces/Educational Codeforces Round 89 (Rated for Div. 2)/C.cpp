#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e1 + 5;

int t, n, m;
int a[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) cin >> a[i][j];
        int tot = n - 1 + m - 1 - 1;
        int ans = a[1][1] == a[n][m] ? 0 : 1;
        for (int i = 1; i <= tot / 2; ++i) {
            int cnt0 = 0, cnt1 = 0;
            if (m >= n) {
                for (int x = 1, y = 1 + i; x <= n && y >= 1; ++x, --y) {
                    if (a[x][y] == 0)
                        ++cnt0;
                    else
                        ++cnt1;
                }
                for (int x = n, y = m - i; x >= 1 && y <= m; --x, ++y) {
                    if (a[x][y] == 0)
                        ++cnt0;
                    else
                        ++cnt1;
                }
            } else {
                for (int y = 1, x = 1 + i; x >= 1 && y <= m; --x, ++y) {
                    if (a[x][y] == 0)
                        ++cnt0;
                    else
                        ++cnt1;
                }
                for (int y = m, x = n - i; x <= n && y >= 1; ++x, --y) {
                    if (a[x][y] == 0)
                        ++cnt0;
                    else
                        ++cnt1;
                }
            }
            ans += min(cnt0, cnt1);
        }
        cout << ans << '\n';
    }

    return 0;
}