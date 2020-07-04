#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;

int t, n, m;
int a[maxn][maxn];

int check(int i, int j) { return (i == 1 || i == n) + (j == 1 || j == m); }

bool solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!check(i, j)) {
                if (a[i][j] <= 4)
                    a[i][j] = 4;
                else
                    return false;
            } else if (check(i, j) == 1) {
                if (a[i][j] <= 3)
                    a[i][j] = 3;
                else
                    return false;
            } else {
                if (a[i][j] <= 2)
                    a[i][j] = 2;
                else
                    return false;
            }
        }
    }
    return true;
}

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
        if (solve()) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) cout << a[i][j] << ' ';
                cout << '\n';
            }
        } else
            cout << "NO\n";
    }
    
    return 0;
}