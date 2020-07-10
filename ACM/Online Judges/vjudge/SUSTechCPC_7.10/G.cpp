#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 998244353;

int T, n;
ll fac[maxn], facinv[maxn];

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

inline void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
    facinv[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i) facinv[i] = facinv[i + 1] * (i + 1) % mod;
}

inline ll C(ll n, ll k) {
    if (!k || n == k) return 1;
    if (n < k || k < 0) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(1e5);
    cin >> T;
    while (T--) {
        cin >> n;
        ll ans = n & 1 ? mod - 1 : 1;
        for (int k = 0; k < n; ++k) {
            if (k & 1)
                ans = ans - (C(n, k) * fac[n - k - 1] % mod) + mod;
            else
                ans = ans + C(n, k) * fac[n - k - 1] % mod;
            ans %= mod;
        }
        cout << ans << '\n';
    }

    return 0;
}