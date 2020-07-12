#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n, x, y;
int a[55], b[55];
map<ll, int> m;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        long long ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        int xx = n >> 1;
        m.clear();
        for (int i = 0; i < 1 << xx; i++) {
            long long sumx = 0, sumy = 0;
            for (int j = 0; j < xx; j++) {
                if ((i >> j) & 1) {
                    sumx += a[j + 1];
                    sumy += b[j + 1];
                }
            }
            m[sumx * y - sumy * x]++;
        }
        xx = n - xx;
        for (int i = 0; i < 1 << xx; i++) {
            long long sumx = 0, sumy = 0;
            for (int j = 0; j < xx; j++) {
                if ((i >> j) & 1) {
                    sumx += a[n - j];
                    sumy += b[n - j];
                }
            }
            ans += m[sumy * x - sumx * y];
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}