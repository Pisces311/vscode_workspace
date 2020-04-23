#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, a, b, c, d;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c >> d;
        if (n * (a - b) <= c + d && n * (a + b) >= c - d)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}