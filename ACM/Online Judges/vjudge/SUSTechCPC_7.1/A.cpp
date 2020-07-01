#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e5 + 5;
constexpr int mod = 1e9 + 7;

int t, n, q;
ll r[maxn], s[maxn], x[maxn], a[maxn];
ll dp[maxn];

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

ll inv(ll x) { return qpow(x, mod - 2); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) cin >> r[i] >> s[i] >> x[i] >> a[i];
        for (int i = 2; i <= n + 1; ++i) {
            ll times = s[i - 1] * inv(r[i - 1]) % mod;
            dp[i] = ((dp[i - 1] - dp[x[i - 1]] + mod) % mod *
                         (times - 1 + mod) % mod +
                     (dp[i - 1] + a[i - 1] * times) % mod) %
                    mod;
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << (dp[r] - dp[l] + mod) % mod << '\n';
        }
    }

    return 0;
}