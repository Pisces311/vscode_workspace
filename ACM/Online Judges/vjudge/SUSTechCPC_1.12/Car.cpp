#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll ans = 0;
        double speed = a[n] - a[n - 1];
        for (int i = n; i >= 1; --i) {
            double len = (a[i] - a[i - 1]) * 1.0;
            int t = len / speed;
            ans += t;
            if (len / t != speed) {
                ans++;
                speed = len / (t + 1);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}