#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, n;
ll m;
ll dig[12];

inline void init() {
    dig[0] = 1;
    for (int i = 1; i <= 10; i++) dig[i] = dig[i - 1] * 10;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll ans = -1, fast = m, slow = m;
        int cnt = 1;
        while (true) {
            if (fast > ans) ans = fast;
            fast *= fast;
            while (fast >= dig[n]) fast /= 10;
            if (++cnt & 1) {
                slow *= slow;
                while (slow >= dig[n]) slow /= 10;
            }
            if (slow == fast) break;
        }
        cout << ans << '\n';
    }

    return 0;
}