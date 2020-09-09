#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int one = accumulate(a + 1, a + n + 1, 0);
        if (one > n / 2) {
            if (one & 1) --one;
            cout << one << '\n';
            for (int i = 1; i <= one; ++i) cout << 1 << " \n"[i == one];
        } else {
            cout << n / 2 << '\n';
            for (int i = 1; i <= n / 2; ++i) cout << 0 << " \n"[i == n / 2];
        }
    }

    return 0;
}