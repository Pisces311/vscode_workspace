#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 4e4 + 5;

int n, m, k;
int a[maxn], b[maxn];
vector<ll> fac, fac2;

void get(ll n) {
    fac.clear();
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            fac.push_back(i);
            fac2.push_back(n / i);
        }
    }
}

int cnt_a(int len) {
    if (len > n) return 0;
    int sum = 0, ans = 0;
    for (int i = 1; i <= len; ++i) sum += a[i];
    if (sum == len) ++ans;
    for (int i = len + 1; i <= n; ++i) {
        sum += a[i] - a[i - len];
        if (sum == len) ++ans;
    }
    return ans;
}

int cnt_b(int len) {
    if (len > m) return 0;
    int sum = 0, ans = 0;
    for (int i = 1; i <= len; ++i) sum += b[i];
    if (sum == len) ++ans;
    for (int i = len + 1; i <= m; ++i) {
        sum += b[i] - b[i - len];
        if (sum == len) ++ans;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    get(k);
    ll ans = 0;
    for (int i = 0; i < fac.size(); ++i) {
        ans += 1ll * cnt_a(fac[i]) * cnt_b(fac2[i]);
        if (fac[i] != fac2[i]) ans += 1ll * cnt_a(fac2[i]) * cnt_b(fac[i]);
    }
    cout << ans << '\n';

    return 0;
}