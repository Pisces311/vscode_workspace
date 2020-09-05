#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll a, b, x, y, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> a >> b >> x >> y >> n;
        if (a - x + b - y <= n)
            cout << x * y << '\n';
        else {
            int sub = min(a - x, n);
            ll ans1 = (a - sub) * (b - (n - sub));
            sub = min(b - y, n);
            ll ans2 = (b - sub) * (a - (n - sub));
            cout << min(ans1, ans2) << '\n';
        }
    }

    return 0;
}