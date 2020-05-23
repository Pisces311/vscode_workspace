#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

ll n, mod;

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

    cin >> n >> mod;
    for (int i = 1; i <= n; ++i) cout << inv(i) << '\n';

    return 0;
}