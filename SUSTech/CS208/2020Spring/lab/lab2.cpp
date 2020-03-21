#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 4e5 + 5;
constexpr int mod = 998244353;

struct number {
    char num[12];
    int len;
    ll pre[12];
} a[maxn];

int n;
ll cnt[12], sum[12];

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
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> (a[i].num + 1);
        a[i].len = strlen(a[i].num + 1);
        ++cnt[a[i].len];
        for (int j = 1; j <= a[i].len; ++j) {
            a[i].pre[j] = a[i].pre[j - 1] * 10 + a[i].num[j] - '0';
            a[i].pre[j] %= mod;
        }
    }
    for (int i = 10; i >= 1; --i) sum[i] = sum[i + 1] + cnt[i];
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= a[i].len; ++j) {
            ans += a[i].pre[a[i].len - j] * qpow(10, 2 * j) % mod *
                   (cnt[j] * 2) % mod;
            ans %= mod;
            ans += (a[i].num[a[i].len - j + 1] - '0') * 11 *
                   qpow(10, 2 * (j - 1)) % mod * sum[j] % mod;
            ans %= mod;
        }
    }
    cout << ans << '\n';

    return 0;
}