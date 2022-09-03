#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

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

ll qpow(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1) ret *= a;
        b /= 2;
        a *= a;
    }
    return ret;
}