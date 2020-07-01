#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, r;

ll cal(ll x) { return (1 + x) * x / 2; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> r;
        ll ans = cal(min(r, n - 1));
        if (r >= n) ++ans;
        cout << ans << '\n';
    }

    return 0;
}