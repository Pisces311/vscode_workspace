#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int t, n, s, k;
int a[maxn];

int solve() {
    for (int i = 0; i <= 1005; ++i) {
        if (s + i <= n && a[lower_bound(a + 1, a + k + 1, s + i) - a] != s + i)
            return i;
        if (s - i >= 1 && a[lower_bound(a + 1, a + k + 1, s - i) - a] != s - i)
            return i;
    }
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> s >> k;
        for (int i = 1; i <= k; ++i) cin >> a[i];
        sort(a + 1, a + k + 1);
        a[k + 1] = 0;
        cout << solve() << '\n';
    }

    return 0;
}