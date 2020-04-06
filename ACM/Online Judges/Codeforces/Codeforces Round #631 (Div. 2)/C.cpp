#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

ll n, m;
ll a[maxn], ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    ll sum = accumulate(a + 1, a + m + 1, 0ll);
    ll more = sum - n;
    if (more < 0) {
        cout << "-1\n";
        return 0;
    }
    ans[1] = 1;
    if (ans[1] + a[1] - 1 > n) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 2; i <= m; ++i) {
        if (more >= a[i - 1] - 1) {
            ans[i] = ans[i - 1] + 1;
            more -= a[i - 1] - 1;
        } else if (more) {
            ans[i] = ans[i - 1] + a[i - 1] - more;
            more = 0;
        } else {
            ans[i] = ans[i - 1] + a[i - 1];
        }
        if (ans[i] + a[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}