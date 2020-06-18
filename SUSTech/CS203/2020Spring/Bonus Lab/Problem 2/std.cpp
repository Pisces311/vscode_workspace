#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;
constexpr int maxn = 2e4 + 5;

int t, n, q, k;
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
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        while (q--) {
            cin >> k;
            cout << a[k] << '\n';
        }
    }

    return 0;
}