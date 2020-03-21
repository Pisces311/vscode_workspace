#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

//模为素数
ll mod;
vector<ll> fac;

void get(ll n) {
    fac.clear();
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fac.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fac.push_back(n);
}

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

bool check(int i) {
    for (int j : fac)
        if (qpow(i, (mod - 1) / j) == 1) return false;
    return true;
}

int find_smallest_proot(ll mod) {
    get(mod - 1);
    for (int i = 2; i < mod; ++i) {
        if (check(i)) return i;
    }
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> mod;
    cout << find_smallest_proot(mod);

    return 0;
}
