#include <bits/stdc++.h>
using namespace std;

class Comb {
    using ll = long long;

    int mod;
    vector<ll> fac, facinv;

    ll qpow(ll a, ll b) {
        ll ret = 1;
        a %= mod;
        for (; b; b >>= 1) {
            if (b & 1) ret = (ret * a) % mod;
            a = (a * a) % mod;
        }
        return ret;
    }

   public:
    Comb(int n, int mod)
        : fac(vector<ll>(n + 1)), facinv(vector<ll>(n + 1)), mod(mod) {
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
        facinv[n] = qpow(fac[n], mod - 2);
        for (int i = n - 1; i >= 0; i--)
            facinv[i] = facinv[i + 1] * (i + 1) % mod;
    }

    ll comb(ll n, ll k) {
        if (!k || n == k) return 1;
        if (n < k || k < 0) return 0;
        return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
    }
};