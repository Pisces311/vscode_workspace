#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int k, n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            int len = min(n - i + 1, a[i]);
            ans = max(ans, len);
        }
        cout << ans << '\n';
    }

    return 0;
}