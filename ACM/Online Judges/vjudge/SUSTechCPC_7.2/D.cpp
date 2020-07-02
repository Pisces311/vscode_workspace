#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 1e9 + 7;

int T, block;
ll res = 2, ans[maxn];
ll fac[maxn], facinv[maxn];

struct query {
    int n, m, in;
    bool operator<(const query& a) const {
        return (m / block) == (a.m / block) ? n < a.n : m < a.m;
    }
} q[maxn];

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

inline void addn(int n, int m) { res = (res * 2 % mod - C(n, m) + mod) % mod; }
inline void subn(int n, int m) {
    res = (res + C(n - 1, m)) % mod * facinv[2] % mod;
}
inline void addm(int n, int m) { res = (res + C(n, m + 1)) % mod; }
inline void subm(int n, int m) { res = (res - C(n, m) + mod) % mod; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(1e5);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n, m;
        cin >> n >> m;
        q[i] = {n, m, i};
    }
    block = sqrt(maxn);
    sort(q + 1, q + T + 1);
    int n = 1, m = 1;
    for (int i = 1; i <= T; ++i) {
        while (n < q[i].n) addn(n++, m);
        while (n > q[i].n) subn(n--, m);
        while (m < q[i].m) addm(n, m++);
        while (m > q[i].m) subm(n, m--);
        ans[q[i].in] = res;
    }
    for (int i = 1; i <= T; ++i) cout << ans[i] << '\n';

    return 0;
}