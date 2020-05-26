#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 4e5 + 5;

int n;
ll x;
ll d[maxn], pre[maxn], hugs[maxn], pre_hugs[maxn];

int bound(ll tar) {
    int l = 0, r = 2 * n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (pre[mid] <= tar) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
    }
    return ans;
}

ll cal(ll s, ll e) { return (s + e) * (e - s + 1) / 2; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    for (int i = 1; i <= 2 * n; ++i) hugs[i] = cal(1, d[i]);
    for (int i = 1; i <= 2 * n; ++i) {
        pre[i] = pre[i - 1] + d[i];
        pre_hugs[i] = pre_hugs[i - 1] + hugs[i];
    }
    ll ans = 0;
    for (int i = n + 1; i <= 2 * n; ++i) {
        int p = bound(pre[i] - x);
        ll cur = pre_hugs[i] - pre_hugs[p + 1];
        ll left = x - (pre[i] - pre[p + 1]);
        cur += cal(d[p + 1] - left + 1, d[p + 1]);
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}