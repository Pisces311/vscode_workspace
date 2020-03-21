#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, n;
int a[maxn << 1];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
        sort(a + 1, a + 2 * n + 1);
        cout << a[n + 1] - a[n] << '\n';
    }

    return 0;
}