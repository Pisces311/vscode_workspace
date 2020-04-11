#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 998244353;

ll n, m, L, R;

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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> L >> R;
    int len = R - L + 1;
    if ((n * m) & 1) {
        cout << qpow(len, n * m) << '\n';
    } else {
        if (len & 1) {
            cout << (qpow(len, n * m) + 1) / 2 << '\n';
        } else {
            cout << qpow(len, n * m) / 2 << '\n';
        }
    }

    return 0;
}