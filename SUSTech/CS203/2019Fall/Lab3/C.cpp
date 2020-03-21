#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e3 + 5;

int n, m;
ll ans = 0;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            ans += upper_bound(a + j + 1, a + n + 1, m - a[i] - a[j]) -
                   lower_bound(a + j + 1, a + n + 1, m - a[i] - a[j]);
    }
    cout << ans << '\n';

    return 0;
}