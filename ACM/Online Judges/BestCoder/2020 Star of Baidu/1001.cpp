#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e4 + 5;
constexpr int inf = 0x3f3f3f3f;

int t, n, m;
int x[maxn], y[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
        int ans = inf;
        for (int i = 1; i <= n; ++i) {
            int cur = ceil(1.0 * m / x[i]);
            ans = min(ans, cur * y[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}