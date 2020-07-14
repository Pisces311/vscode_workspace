#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int m;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cas = 0;
    while (cin >> m) {
        int ans = log10(2) * m;
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }

    return 0;
}