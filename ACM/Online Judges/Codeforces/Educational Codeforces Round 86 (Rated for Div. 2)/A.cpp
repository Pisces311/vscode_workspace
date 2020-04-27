#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll x, y, a, b;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> x >> y;
        cin >> a >> b;
        if (2 * a <= b)
            cout << (x + y) * a << '\n';
        else {
            cout << min(x, y) * b + abs(x - y) * a << '\n';
        }
    }

    return 0;
}