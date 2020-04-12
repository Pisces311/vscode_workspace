#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;
constexpr int mod = 998244353;

ll w, q;
ll ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> q;
    ans[1] = w;
    for (int i = 2, j = 3; i < maxn; ++i, j += 2)
        ans[i] = (ans[i - 1] * j) % mod;
    while (q--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}