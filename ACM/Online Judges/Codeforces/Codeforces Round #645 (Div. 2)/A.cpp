#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, m;

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
        int ans = 0;
        ans += n / 2 * m;
        n %= 2;
        if (n) {
            ans += m / 2;
            m %= 2;
            if (m) ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}