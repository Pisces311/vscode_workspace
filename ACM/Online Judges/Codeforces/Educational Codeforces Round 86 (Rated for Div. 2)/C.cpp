#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll a, b, q, l, r;
ll cnt[205 * 205];

ll query(ll num) { return num / (a * b) * cnt[a * b - 1] + cnt[num % (a * b)]; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> a >> b >> q;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < a * b; ++i)
            if (i % a % b != i % b % a) cnt[i] = 1;
        for (int i = 0; i < a * b; ++i) cnt[i] = cnt[i - 1] + cnt[i];
        while (q--) {
            cin >> l >> r;
            cout << query(r) - query(l - 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}