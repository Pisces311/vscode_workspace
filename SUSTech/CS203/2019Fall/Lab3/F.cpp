#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct bead {
    int a, b;
    bool operator<(const bead& x) const {
        if (a < b && x.a >= x.b)
            return true;
        else if (a >= b && x.a < x.b)
            return false;
        else if (a < b && x.a < x.b)
            return a < x.a;
        else
            return b > x.b;
    }
} a[maxn];

int T, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i].a >> a[i].b;
        sort(a + 1, a + n + 1);
        int Red = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (Red >= a[i].a) {
                ans += a[i].a;
                Red += a[i].b - a[i].a;
            } else {
                ans += Red;
                Red = a[i].b;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}