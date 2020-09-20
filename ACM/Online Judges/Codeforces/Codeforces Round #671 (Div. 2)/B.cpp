#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 6e1 + 5;

int t;
ll x;
ll a[maxn], pre[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    a[1] = 1;
    for (ll i = 2, j = 2; i <= 61; ++i, j *= 2) a[i] = 2 * a[i - 1] + j * j;
    for (int i = 1; i <= 61; ++i) pre[i] = pre[i - 1] + a[i];
    cin >> t;
    while (t--) {
        cin >> x;
        for (int i = 1; i <= 61; ++i)
            if (pre[i] > x) {
                cout << i - 1 << '\n';
                break;
            }
    }

    return 0;
}