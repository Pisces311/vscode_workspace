#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll a, m;
vector<ll> p;
bool isp[maxn];

ll qpow(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1) ret *= a;
        b /= 2;
        a *= a;
    }
    return ret;
}

void solve() {
    ll g = __gcd(a, m);
    a /= g;
    m /= g;
    ll ans = 1;
    for (ll i : p) {
        if (i * i > m) break;
        if (m % i == 0) {
            m /= i;
            ans *= i - 1;
            while (m % i == 0) {
                m /= i;
                ans *= i;
            }
        }
    }
    if (m != 1) {
        ans *= m - 1;
    }
    cout << ans << '\n';
}

inline void init() {
    for (int i = 2; i < maxn; ++i) {
        if (!isp[i]) p.push_back(i);
        for (int j = 0; i * p[j] < maxn; ++j) {
            isp[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> T;
    while (T--) {
        cin >> a >> m;
        solve();
    }

    return 0;
}