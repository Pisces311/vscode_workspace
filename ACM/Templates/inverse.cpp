#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1e9 + 7;

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

// 处理模数为质数的情况
ll inv(ll x) { return qpow(x, mod - 2); }

// 任意模数
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