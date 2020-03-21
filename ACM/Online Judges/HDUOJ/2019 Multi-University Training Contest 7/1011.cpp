#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;

int t, n, q, l, r, p, q, a, x;
int dp[maxn];

int quick_pow(ll a, int n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> p >> q >> x >> a;
            ll tmp = (dp[i - 1] - dp[x - 1] + mod) % mod;
            dp[i] = (tmp + a) % mod * q % mod * quick_pow(p, mod - 2) % mod;
            dp[i] = (dp[i] - tmp + mod) % mod;
            dp[i] = (dp[i - 1] + dp[i]) % mod;
        }
        while (q--) {
            cin >> l >> r;
            cout << (dp[r - 1] - dp[l - 1] + mod) % mod << '\n';
        }
    }

    return 0;
}