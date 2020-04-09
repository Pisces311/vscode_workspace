#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int t, n, m;
char g[maxn][maxn];

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
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) g[i][j] = 'B';
        }
        g[1][1] = 'W';
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << g[i][j];
            cout << '\n';
        }
    }

    return 0;
}