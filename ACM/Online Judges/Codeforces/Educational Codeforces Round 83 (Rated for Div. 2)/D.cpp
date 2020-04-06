#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;
constexpr ll mod = 998244353;

int n, m;

ll inv(ll a, ll m) {
    if (a == 1) return 1;
    return inv(m % a, m) * (m - m / a) % m;
}

ll C(ll a, ll b) {
    ll res = 1;
    for (int i = a - b + 1; i <= a; i++) res = res * i % mod;
    for (int i = 2; i <= b; i++) res = res * inv(i, mod) % mod;
    return res;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    if (n > m + 1 || n == 2)
        cout << "0\n";
    else {
        ll combination = C(m, n - 1) * (n - 2) % mod;
        ll pow = 1;
        for (int i = 1; i <= n - 3; ++i) pow = pow * 2 % mod;
        ll ans = combination * pow % mod;
        cout << ans << '\n';
    }

    return 0;
}