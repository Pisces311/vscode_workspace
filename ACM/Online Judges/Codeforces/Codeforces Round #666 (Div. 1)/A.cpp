#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
ll a[maxn], b[maxn], x[maxn];

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        if (!a) return -1;
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -x[1] << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        ex_gcd(n, n - 1, a[i], b[i]);
        a[i] = -a[i] * x[i] * n;
        b[i] = -b[i] * x[i] * (n - 1);
    }
    cout << 1 << ' ' << n << '\n';
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 1; i <= n - 1; ++i) cout << b[i] << " \n"[i == n - 1];
    cout << n << ' ' << n << '\n';
    cout << -(x[n] + a[n]) << '\n';

    return 0;
}
