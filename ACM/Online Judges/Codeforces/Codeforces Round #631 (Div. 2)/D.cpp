#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll d, m;
ll cnt[40];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cnt[1] = 1;
    for (int i = 2; i <= 30; ++i) cnt[i] = cnt[i - 1] * 2;
    cin >> t;
    while (t--) {
        cin >> d >> m;
        ll ans = 1;
        for (int i = 1; i <= 30; ++i) {
            if (d >= cnt[i]) {
                ans *= (cnt[i] + 1) % m;
                ans %= m;
                d -= cnt[i];
            } else {
                ans *= (d + 1) % m;
                ans %= m;
                break;
            }
        }
        cout << (ans - 1 + m) % m << '\n';
    }

    return 0;
}