#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
ll l, r;
ll num[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> l >> r;
        for (int i = 1; i <= n; ++i) num[i] = 2 * (n - i);
        ll cnt = 0;
        int level = 0, pos = 0;
        while (cnt < l) {
            ++level;
            if (level == n) {
                cout << "1 ";
                cnt = r + 1;
                break;
            }
            if (cnt + num[level] < l) {
                cnt += num[level];
            } else {
                pos = l - cnt;
                cnt = l;
                break;
            }
        }
        for (int i = pos; cnt <= r && i <= num[level]; ++i) {
            if (i & 1)
                cout << level << ' ';
            else
                cout << (i / 2 + level) << ' ';
            ++cnt;
        }
        while (cnt <= r) {
            ++level;
            if (level == n) {
                cout << "1 ";
                break;
            }
            for (int i = 1; cnt <= r && i <= num[level]; ++i) {
                if (i & 1)
                    cout << level << ' ';
                else
                    cout << (i / 2 + level) << ' ';
                ++cnt;
            }
        }
        cout << '\n';
    }

    return 0;
}