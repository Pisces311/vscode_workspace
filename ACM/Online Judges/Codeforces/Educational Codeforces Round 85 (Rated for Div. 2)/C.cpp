#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int T, n;
ll a[maxn], b[maxn];
ll add[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                add[i] = max(0ll, a[i] - b[n]);
            } else {
                add[i] = max(0ll, a[i] - b[i - 1]);
            }
        }
        ll sum = accumulate(add + 1, add + n + 1, 0ll);
        ll ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            ll cur = a[i] + sum - add[i];
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }

    return 0;
}