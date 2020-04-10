#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
ll x;
ll a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        ll sum = 0;
        int cnt = 0;
        for (int i = n; i >= 1; --i) {
            sum += a[i];
            if (sum < (n - i + 1) * x) break;
            ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}