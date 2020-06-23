#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n, k;
int a[maxn], w[maxn], big[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= k; ++i) cin >> w[i];
        sort(w + 1, w + k + 1);
        ll ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans += a[i];
            big[i] = a[i];
        }
        int last = k + 1;
        for (int i = 1; i <= k; ++i) {
            if (w[i] == 1)
                ans += big[i];
            else {
                ans += a[last + w[i] - 2];
                last = last + w[i] - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}