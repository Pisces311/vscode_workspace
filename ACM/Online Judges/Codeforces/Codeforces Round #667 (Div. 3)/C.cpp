#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int maxn = 1e5 + 5;

int t;
int n, x, y;

pii solve() {
    int ma = 0x3f3f3f3f;
    pii ret;
    for (int i = 1; i <= y - x; ++i) {
        if ((y - x) % i == 0) {
            int st = y - (n - 1) * i;
            if (st <= 0) st = y % i;
            if (!st) st += i;
            if (st > x) continue;
            int cur = st + (n - 1) * i;
            if (ma > cur) {
                ma = cur;
                ret = make_pair(st, i);
            }
        }
    }
    return ret;
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
        cin >> n >> x >> y;
        pii ans = solve();
        for (int i = ans.first, j = 1; j <= n; i += ans.second, ++j)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}