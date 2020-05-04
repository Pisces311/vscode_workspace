#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;
constexpr int mod = 998244353;

ll n, k;
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

inline void init() {
    fac[1] = 1;
    for (int i = 2; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
    facinv[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 1; --i) facinv[i] = facinv[i + 1] * (i + 1) % mod;
}

inline ll C(ll n, ll k) {
    if (!k || n == k) return 1;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    init();
    ll c = n - k;
    if (c <= 0) {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= c; ++i) {
        ll ret = C(c, i) * qpow(c - i, n) % mod;
        if (i & 1)
            ans -= ret;
        else
            ans += ret;
        ans = (ans + mod) % mod;
    }
    ans = ans * C(n, c) % mod;
    cout << (k ? ans * 2 % mod : ans) << '\n';

    return 0;
}