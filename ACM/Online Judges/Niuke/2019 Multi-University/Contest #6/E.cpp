#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int T, n;
int g[maxn][maxn];

void solve() {
    if (n % 4 > 1) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    int m = n / 4 * 4;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= m; ++i) {
        if ((i % 4) <= 1) {
            for (int j = (i % 4 ? i + 4 : i + 1); j <= m; ++j)
                g[i][j] = g[j][i] = 1;
            if (n != m) g[i][n] = g[n][i] = 1;
        }
        if ((i % 4) == 0)
            for (int j = i; j > i - 3; --j) g[j][j - 1] = g[j - 1][j] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << g[i][j];
        cout << '\n';
    }
    for (int i = 0; i < n / 4; ++i) {
        if (i != 0) cout << ' ';
        cout << 2 + i * 4 << ' ' << 4 + i * 4 << ' ' << 1 + i * 4 << ' '
             << 3 + i * 4;
    }
    if (n > 1 && n != m)
        cout << ' ' << n << '\n';
    else if (n != m)
        cout << 1 << '\n';
    else
        cout << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> n;
        solve();
    }

    return 0;
}