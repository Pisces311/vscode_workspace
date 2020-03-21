#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod;
map<ll, ll> mp;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

ll ex_BSGS(ll A, ll B, ll mod) {
    if (B == 1) return 0;
    ll k = 0, tmp = 1, d;
    while (true) {
        d = gcd(A, mod);
        if (d == 1) break;
        if (B % d) return -1;
        B /= d;
        mod /= d;
        tmp = 1ll * tmp * (A / d) % mod;
        k++;
        if (tmp == B) return k;
    }
    mp.clear();
    ll mul = B;
    mp[B] = 0;
    ll m = ceil(sqrt(1.0 * mod));
    for (ll j = 1; j <= m; ++j) {
        mul = 1ll * mul * A % mod;
        mp[mul] = j;
    }
    ll am = qpow(A, m);
    mul = tmp;
    for (ll j = 1; j <= m; ++j) {
        mul = 1ll * mul * am % mod;
        if (mp.count(mul)) return j * m - mp[mul] + k;
    }
    return -1;
}