#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
int a[5];

int main() {
#ifdef DEBUG
    freopen("SUSTech/BBCC/Identity V/Input/6.in", "r", stdin);
    freopen("SUSTech/BBCC/Identity V/Output/6.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            int x, w;
            cin >> x >> w;
            if (x == 1) {
                while (w && x <= 4) {
                    int add = min(3000 - a[x], w);
                    w -= add;
                    a[x] += add;
                    ++x;
                }
            } else {
                a[x] = min(a[x] + w, 3000);
            }
        }
        cout << accumulate(a + 1, a + 5, 0) << '\n';
    }

    return 0;
}