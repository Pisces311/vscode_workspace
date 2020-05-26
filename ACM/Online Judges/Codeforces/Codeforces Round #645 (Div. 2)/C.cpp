#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll x[3], y[3];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> x[1] >> y[1] >> x[2] >> y[2];
        ll ans = 0;
        ll times = (y[2] - y[1]) + (x[2] - x[1]) - 1;
        ll top = min(y[2] - y[1], x[2] - x[1]) - 1;
        ans += top * (top + 1);
        ll r = times - 2 * top;
        ans += r * (top + 1);
        cout << ans + 1 << '\n';
    }

    return 0;
}