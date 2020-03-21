#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N, Sum;
ll y, z, mod;

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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

map<ll, ll> mp;
ll ex_BSGS(ll A, ll B, ll mod) {
    if (B == 1) return 0;
    ll k = 0, tmp = 1, d;
    while (true) {
        d = gcd(A, mod);
        if (d == 1) break;
        if (B % d) return -1;
        B /= d;
        mod /= d;
        tmp = 1LL * tmp * (A / d) % mod;
        k++;
        if (tmp == B) return k;
    }
    mp.clear();
    ll mul = B;
    mp[B] = 0;
    ll m = ceil(sqrt(1.0 * mod));
    for (ll j = 1; j <= m; ++j) {
        mul = 1LL * mul * A % mod;
        mp[mul] = j;
    }
    ll am = qpow(A, m);
    mul = tmp;
    for (ll j = 1; j <= m; ++j) {
        mul = 1LL * mul * am % mod;
        if (mp.count(mul)) return j * m - mp[mul] + k;
    }
    return -1;
}

namespace zyt {
const int N = 1e6;
typedef long long ll;
ll n, m, p;
inline ll power(ll a, ll b, const ll p = LLONG_MAX) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
ll fac(const ll n, const ll p, const ll pk) {
    if (!n) return 1;
    ll ans = 1;
    for (int i = 1; i < pk; i++)
        if (i % p) ans = ans * i % pk;
    ans = power(ans, n / pk, pk);
    for (int i = 1; i <= n % pk; i++)
        if (i % p) ans = ans * i % pk;
    return ans * fac(n / p, p, pk) % pk;
}
ll exgcd(const ll a, const ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll xx, yy, g = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;
    return g;
}
ll inv(const ll a, const ll p) {
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}
ll C(const ll n, const ll m, const ll p, const ll pk) {
    if (n < m) return 0;
    ll f1 = fac(n, p, pk), f2 = fac(m, p, pk), f3 = fac(n - m, p, pk), cnt = 0;
    for (ll i = n; i; i /= p) cnt += i / p;
    for (ll i = m; i; i /= p) cnt -= i / p;
    for (ll i = n - m; i; i /= p) cnt -= i / p;
    return f1 * inv(f2, pk) % pk * inv(f3, pk) % pk * power(p, cnt, pk) % pk;
}
ll a[N], c[N];
int cnt;
inline ll CRT() {
    ll M = 1, ans = 0;
    for (int i = 0; i < cnt; i++) M *= c[i];
    for (int i = 0; i < cnt; i++)
        ans = (ans + a[i] * (M / c[i]) % M * inv(M / c[i], c[i]) % M) % M;
    return ans;
}
ll exlucas(const ll n, const ll m, ll p) {
    ll tmp = sqrt(p);
    for (int i = 2; p > 1 && i <= tmp; i++) {
        ll tmp = 1;
        while (p % i == 0) p /= i, tmp *= i;
        if (tmp > 1) a[cnt] = C(n, m, i, tmp), c[cnt++] = tmp;
    }
    if (p > 1) a[cnt] = C(n, m, p, p), c[cnt++] = p;
    return CRT();
}
void init() {
    cnt = 0;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
}
int work(ll x, ll y, ll z) {
    init();
    n = x, m = y, p = z;
    cout << exlucas(n, m, p) << '\n';
    return 0;
}
}  // namespace zyt

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> Sum >> y >> z >> mod;
        if (Sum == 1) {
            cout << qpow(y, z) << '\n';
        } else if (Sum == 2) {
            ll ret = ex_BSGS(y, z, mod);
            if (ret != -1)
                cout << ret << '\n';
            else
                cout << "Math Error\n";
        } else {
            zyt::work(z, y, mod);
        }
    }

    return 0;
}