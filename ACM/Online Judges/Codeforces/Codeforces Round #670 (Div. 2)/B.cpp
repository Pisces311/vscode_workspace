#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr ll inf = 1ll << 60;

int t, n;
ll a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        ll ans = -inf;
        ans = max(ans, a[n] * a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4]);
        ans = max(ans, a[n] * a[n - 1] * a[n - 2] * a[1] * a[2]);
        ans = max(ans, a[n] * a[1] * a[2] * a[3] * a[4]);
        cout << ans << '\n';
    }

    return 0;
}