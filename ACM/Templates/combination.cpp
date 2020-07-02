#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 998244353;

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
    fac[1] = 1;
    for (int i = 2; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
    facinv[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 1; --i) facinv[i] = facinv[i + 1] * (i + 1) % mod;
}

inline ll C(ll n, ll k) {
    if (!k || n == k) return 1;
    if (n < k) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}