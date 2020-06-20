#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, k;
int a[maxn];

bool check(int mid) {
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        if (num & 1)
            ++num;
        else if (a[i] <= mid)
            ++num;
    }
    if (num >= k) return true;
    num = 0;
    for (int i = 1; i <= n; ++i) {
        if (!(num & 1))
            ++num;
        else if (a[i] <= mid)
            ++num;
    }
    if (num >= k) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 1, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    cout << ans << '\n';

    return 0;
}