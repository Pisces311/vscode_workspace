#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        int ans = 0;
        while (x != y) {
            if (x > y) swap(x, y);
            y /= 2;
            ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}