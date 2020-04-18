#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

ll a[5];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> a[1] >> a[2] >> a[3]) {
        sort(a + 1, a + 4);
        ll ans = 0;
        ans += max(0ll, a[3] - 1 - a[1]);
        ans += max(0ll, a[3] - 1 - a[2]);
        cout << ans << '\n';
    }

    return 0;
}