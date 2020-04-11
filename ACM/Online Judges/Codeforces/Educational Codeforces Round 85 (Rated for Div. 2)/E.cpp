#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;

ll d;
int q;
vector<ll> fac;
int C[60][60];

void get(int n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fac.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fac.push_back(n);
}

void init() {
    for (int i = 0; i < 60; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

int count(ll a, ll b) {
    int res = 1, sum = 0;
    for (ll i : fac) {
        int x = 0;
        for (; a % i == 0; a /= i) ++x;
        for (; b % i == 0; b /= i) --x;
        sum += x;
        res = 1ll * res * C[sum][x] % mod;
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d;
    get(d);
    init();
    cin >> q;
    while (q--) {
        ll u, v;
        cin >> u >> v;
        ll g = __gcd(u, v);
        cout << 1ll * count(u, g) * count(v, g) % mod << '\n';
    }

    return 0;
}