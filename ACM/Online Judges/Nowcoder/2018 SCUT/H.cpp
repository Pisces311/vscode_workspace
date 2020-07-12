#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int n;
ll mod;
ll mat[maxn][maxn], ans[maxn][maxn];

void ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b)
        x = 1, y = 0;
    else {
        ex_gcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

ll inv(int i) {
    ll x, y;
    ex_gcd(i, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> mod) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) cin >> mat[i][j];
        ll inverse = inv(2);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans[i][j] =
                    ((mat[i][j] - mat[j][i]) * inverse % mod + mod) % mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}