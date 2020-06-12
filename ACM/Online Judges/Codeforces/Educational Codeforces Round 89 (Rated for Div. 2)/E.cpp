#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;
constexpr int mod = 998244353;

int n, m, a[maxn], b[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    int ans = 1;
    for (int i = m, j = n; i >= 1; --i) {
        while (a[j] > b[i]) --j;
        if (a[j] != b[i]) {
            ans = 0;
            break;
        }
        int pos = j;
        while (a[j] >= b[i]) --j;
        if (i > 1)
            ans = (ll)ans * (pos - j) % mod;
        else if (j != 0)
            ans = 0;
    }
    cout << ans << '\n';

    return 0;
}