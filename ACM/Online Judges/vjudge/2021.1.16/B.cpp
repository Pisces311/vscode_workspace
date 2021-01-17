#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 8e3 + 5;

#define int long long

int n, k;
int a[maxn];

int cal(int p) {
    int times = k - p + 1, cap = a[k];
    for (int i = 1; i < p; ++i) {
        int l = i, r = p - i;
        if (l > r) break;
        if (l != r)
            cap = max(cap, a[l] + a[r]);
        else
            cap = max(cap, a[l]);
        ++times;
    }
    return times * cap;
}

int32_t main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ++a[x];
    }
    sort(a + 1, a + k + 1);
    int ans = INT_MAX;
    for (int i = k + 1; i >= 1; --i) ans = min(ans, cal(i));
    cout << ans << '\n';

    return 0;
}