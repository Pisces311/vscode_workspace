#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n;
ll p[50];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p[1] = 2;
    for (int i = 2; i <= 30; ++i) p[i] = 2 * p[i - 1];
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n / 2 - 1; ++i) ans += p[i];
        ans += p[n];
        for (int i = n / 2; i < n; ++i) ans -= p[i];
        cout << abs(ans) << '\n';
    }

    return 0;
}