#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, m;
ll k;

ll gcd(ll a, ll b) { return a == 0 ? b : gcd(b % a, a); }

ll f(ll n, ll m) {
    for (ll i = n + 1; i <= LLONG_MAX; ++i) {
        if (gcd(i, n) == 1) --m;
        if (!m) return i;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> k >> m;
        for (ll n = max(k - 500, 1ll); n <= k + 500; ++n) {
            ll res = f(n, m);
            if (((res - n) ^ n) == k) {
                cout << n << '\n';
                break;
            }
            if (n == k + 500) cout << -1 << '\n';
        }
    }

    return 0;
}