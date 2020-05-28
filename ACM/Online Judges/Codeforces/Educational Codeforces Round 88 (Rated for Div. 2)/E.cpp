#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;
constexpr int mod = 998244353;

int n, k;
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
    for (int i = 2; i <= 1000000; ++i) fac[i] = fac[i - 1] * i % mod;
    facinv[1000000] = qpow(fac[1000000], mod - 2);
    for (int i = 999999; i >= 1; --i) facinv[i] = facinv[i + 1] * (i + 1) % mod;
}

inline ll C(ll n, ll k) {
    if (!k || n == k) return 1;
    if (n < k) return 0;
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
    ll ans = 0;
    init();
    for (int i = 1; i <= n; ++i) {
        int num = n / i;
        ans = (ans + C(num - 1, k - 1)) % mod;
    }
    cout << ans << '\n';

    return 0;
}