#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, a, b;

int use(int x, int y) {
    if (x >= 2 * y)
        return y;
    else if (x >= y) {
        int c = x - y;
        x -= 2 * c;
        return c + 2 * (x / 3) + (x % 3 == 2);
    } else
        return 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << max(use(a, b), use(b, a)) << '\n';
    }

    return 0;
}