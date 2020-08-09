#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr ll mod = 998244353;

int T;
ll m, p, q;

ll qpow(ll a, ll b) {
    ll ret = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

ll inv(ll x) { return qpow(x, mod - 2); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> m >> p >> q;
        ll phit = p * inv(100) % mod, qhit = q * inv(100) % mod;
        ll add = m * inv(phit) % mod;
        ll sub = (add - 1 + mod) % mod * qhit % mod;
        ll ans = (m - sub + mod) % mod;
        cout << ans << '\n';
    }

    return 0;
}