#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

int n, m;
ll fac[maxn];

void init() {
    ll i;
    fac[0] = 1;
    for (ll i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll inv(ll a, ll n) {
    ll x, y;
    exgcd(a, n, x, y);
    return (x + n) % n;
}

ll C(ll n, ll m) { return fac[n] * inv(fac[m] * fac[n - m] % mod, mod) % mod; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    ll ans = 0;
    init();
    for (int i = 1; i <= n; ++i) {
        ll cur = C(m + i - 1, i - 1) * C(m - 1 + n - i, n - i) % mod;
        ans = (ans + cur) % mod;
    }
    cout << ans << '\n';

    return 0;
}