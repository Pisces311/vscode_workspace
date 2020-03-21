#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

namespace Linear_sieves {
const int P = 300005;
int prime[P], pcnt;
bool mark[P];

inline void init(int len = P - 5) {
    mark[1] = true;
    for (int register i = 2; i <= len; ++i) {
        if (!mark[i]) prime[++pcnt] = i;
        for (int register j = 1; j <= pcnt && i * prime[j] <= len; ++j) {
            mark[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
}  // namespace Linear_sieves

namespace Find_root {
#define complex COMPLEX
using namespace Linear_sieves;

inline ll mul(const ll &a, const ll &b, const ll &mod) {
    return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod;
}
inline ll quickpow(ll a, ll b, const ll &mod, ll res = 1) {
    for (; b; b >>= 1, a = mul(a, a, mod))
        if (b & 1) res = mul(res, a, mod);
    return res;
}

inline ll ex_gcd(const ll &a, const ll &b, ll &x, ll &y) {
    if (!b) {
        y = 0;
        x = 1;
        return a;
    }
    ll t = ex_gcd(b, a - a / b * b, y, x);
    y -= (a / b) * x;
    return t;
}
inline ll inv(const ll a, const ll mod) {
    ll x, y;
    ll t = ex_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

ll W, Mod;
class complex {
   public:
    ll x, y;
    complex(const ll &_x = 0, const ll &_y = 0) : x(_x), y(_y) {}
    inline friend complex operator*(const complex &a, const complex &b) {
        return complex(
            (mul(a.x, b.x, Mod) + mul(mul(a.y, b.y, Mod), W, Mod)) % Mod,
            (mul(a.x, b.y, Mod) + mul(a.y, b.x, Mod)) % Mod);
    }
};

complex quickpow(complex a, ll b) {
    complex res(1, 0);
    for (; b; b >>= 1, a = a * a)
        if (b & 1) res = res * a;
    return res;
}

inline bool isprime(ll x) {
    if (x <= P - 5) return !mark[x];
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0 || x % 31 == 0 ||
        x % 24251 == 0)
        return false;
    register ll t = x - 1, s;
    t >>= (s = __builtin_ctzll(t));
    for (int register i = 1; i <= 5; ++i) {
        register ll p = prime[rand() % pcnt + 1];
        register ll num = quickpow(p, t, x), pre = num;
        for (int register j = 0; j < s; ++j) {
            num = mul(num, num, x);
            if (num == 1 && pre != x - 1 && pre != 1) return false;
            pre = num;
            if (num == 1) break;
        }
        if (num ^ 1) return false;
    }
    return true;
}

inline ll Pollard_rho(ll x) {
    if (x % 2 == 0) return 2;
    if (x % 3 == 0) return 3;
    if (x % 5 == 0) return 5;
    if (x % 7 == 0) return 7;
    if (x % 31 == 0) return 31;
    if (x % 24251 == 0) return 24251;
    register ll n = 0, m = 0, t = 1, q = 1, c = rand() % (x - 2) + 2;
    for (int register k = 2;; k <<= 1, m = n, q = 1) {
        for (int register i = 1; i <= k; ++i) {
            n = (mul(n, n, x) + c) % x;
            q = mul(q, abs(n - m), x);
        }
        if ((t = __gcd(q, x)) > 1) return t;
    }
}

ll fact[60], cntf;
inline void sieves(ll x) {
    if (x == 1) return;
    if (isprime(x)) {
        fact[++cntf] = x;
        return;
    }
    register ll p = x;
    while (p == x) p = Pollard_rho(p);
    sieves(p);
    while (x % p == 0) x /= p;
    sieves(x);
}

inline ll solve_2k(ll a, ll k) {
    if (a % (1 << k) == 0) return 0;
    a %= (1 << k);
    register ll t = 0, res = 1;
    a >>= (t = __builtin_ctzll(a));
    if ((a & 7) ^ 1) return -1;
    if (t & 1) return -1;
    k -= t;
    for (int register i = 4; i <= k; ++i) {
        res = (res + (a % (1 << i) - res * res) / 2) % (1 << k);
    }
    res %= 1 << k;
    if (res < 0) res += 1 << k;
    return res << (t >> 1);
}

inline ll solve_p(ll a, ll p) {
    a %= p;
    if (quickpow(a, (p - 1) >> 1, p) == p - 1) return -1;
    register ll b;
    Mod = p;
    while (true) {
        b = rand() % p;
        W = (mul(b, b, p) - a + p) % p;
        if (quickpow(W, (p - 1) >> 1, p) == p - 1) break;
    }
    register ll ans = quickpow(complex(b, 1), (p + 1) >> 1).x;
    return min(ans, p - ans);
}

inline ll solve_pk(ll a, ll k, ll p, ll mod) {
    if (a % mod == 0) return 0;
    register ll t = 0, hmod = 1;
    while (a % p == 0) a /= p, ++t, hmod *= (t & 1) ? p : 1;
    if (t & 1) return -1;
    k -= t;
    mod /= hmod * hmod;
    register ll res = solve_p(a, p);
    if (res == -1) return -1;
    complex tmp(res, 1);
    W = a;
    Mod = mod;
    tmp = quickpow(tmp, k);
    res = mul(tmp.x, inv(tmp.y, Mod), Mod);
    return res * hmod;
}

ll remain[20], mod[20], p;
inline ll CRT() {
    register ll ans = 0;
    for (int register i = 1; i <= cntf; ++i) {
        ans = (ans +
               mul(mul(p / mod[i], inv(p / mod[i], mod[i]), p), remain[i], p)) %
              p;
    }
    return ans;
}

inline ll solve(ll a, ll pmod) {
    a %= pmod;
    cntf = 0;
    p = pmod;
    sieves(pmod);
    if (cntf > 1) sort(fact + 1, fact + cntf + 1);
    if (cntf > 1) cntf = unique(fact + 1, fact + cntf + 1) - fact - 1;
    for (int register i = 1; i <= cntf; ++i) {
        register ll now = 0, rmod = 1;
        while (pmod % fact[i] == 0) pmod /= fact[i], ++now, rmod *= fact[i];
        mod[i] = rmod;
        if (fact[i] == 2)
            remain[i] = solve_2k(a, now);
        else
            remain[i] = solve_pk(a, now, fact[i], rmod);
        if (remain[i] == -1) return -1;
    }
    return CRT();
}

#undef complex
}  // namespace Find_root

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    Linear_sieves::init();
    ll a, mod;
    cin >> a >> mod;
    cout << Find_root::solve(a, mod) << '\n';

    return 0;
}