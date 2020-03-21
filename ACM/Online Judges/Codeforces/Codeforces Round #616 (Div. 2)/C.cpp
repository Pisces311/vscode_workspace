#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 35e2 + 5;

int t, n, m, k;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        k = min(k, m - 1);
        int ans = -1;
        for (int st = 1; st <= k + 1; ++st) {
            int l = st, r = n - k + st - 1;
            int cur = INT_MAX;
            for (int i = l, j = r - (m - k - 1); j <= r; ++i, ++j)
                cur = min(cur, max(a[i], a[j]));
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }

    return 0;
}