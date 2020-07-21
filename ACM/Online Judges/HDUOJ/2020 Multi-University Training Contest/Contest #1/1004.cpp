#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int mod = 998244353;

int T, n;

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
        if (n <= 3) {
            int ans = 1;
            for (int i = 1; i <= n; ++i) ans *= 26;
            cout << ans << '\n';
        } else
            cout << 26 * 25 * 24 << '\n';
    }

    return 0;
}