#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int T, n, m;
ll sum;
ll fac[maxn];

void get_fac() {
    fac[0] = fac[1] = 1;
    up(i, 2, maxn) fac[i] = fac[i - 1] * i % mod;
}

inline ll power(ll a, ll b) {
    ll r = 1, t = a;
    while (b) {
        if (b & 1) r = (r * t) % mod;
        b >>= 1;
        t = (t * t) % mod;
    }
    return r;
}

inline ll inv(ll b) {
    return b == 1 ? 1 : (mod - mod / b) * inv(mod % b) % mod;
}

ll comb(ll n, ll m) {
    return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    get_fac();
    cin >> T;
    while (T--) {
        sum = 0;
        cin >> n >> m;
        m = abs(m);
        ll l, r, dif = n - m;
        up(i, 0, dif) {
            if ((dif - i) & 1) continue;
            l = (dif - i) / 2;
            r = l + m;
            sum += comb(n, i) * comb(n - i, l) % mod *
                   inv(power(2, n + l + r) % mod);
            sum %= mod;
        }
        cout << sum << endl;
    }

    return 0;
}