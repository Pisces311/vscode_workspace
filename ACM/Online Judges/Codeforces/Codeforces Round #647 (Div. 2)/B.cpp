#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;
constexpr int mod = 1e9 + 7;

int t, n, tot;
int k[maxn];
int num[maxn];
ll p;

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

int cal(int i, ll more) {
    ll sum = 0;
    for (int j = 1; j <= n; j += num[k[j]]) {
        if (k[j] > i) break;
        sum += num[k[j]] * qpow(p, k[j]) % mod;
        sum %= mod;
    }
    return (more * qpow(p, i) % mod - sum + mod) % mod;
}

int solve(int Max) {
    ll more = 0;
    for (int i = Max; i >= 0; --i) {
        more *= p;
        if (more >= tot) return cal(i, more);
        if (num[i] > more) {
            if ((num[i] - more) & 1)
                more = 1;
            else
                more = 0;
        } else
            more -= num[i];
        tot -= num[i];
    }
    if (more)
        return 1;
    else
        return 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> p;
        tot = n;
        int Max = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> k[i];
            Max = max(Max, k[i]);
            ++num[k[i]];
        }
        sort(k + 1, k + n + 1);
        if (p == 1)
            cout << n % 2 << '\n';
        else
            cout << solve(Max) << '\n';
        for (int i = 1; i <= n; ++i) num[k[i]] = 0;
    }

    return 0;
}