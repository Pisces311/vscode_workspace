#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int q, c, m, x;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> c >> m >> x;
        int l = 0, r = 1e8, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (c >= mid && m >= mid) {
                if (c - mid + m - mid + x >= mid) {
                    ans = mid;
                    l = mid + 1;
                } else
                    r = mid - 1;
            } else
                r = mid - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}