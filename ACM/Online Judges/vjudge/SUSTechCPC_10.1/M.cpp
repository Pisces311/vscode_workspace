#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N, C, T;
int a[maxn];

bool check(int mid) {
    ll t = 1ll * mid * T;
    int cnt = C - 1;
    for (int i = 1; i <= N; ++i) {
        if (t < a[i]) {
            t = 1ll * mid * T - a[i];
            --cnt;
            if (t < 0 || cnt < 0) return false;
        } else
            t -= a[i];
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C >> T;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    int l = 1, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << '\n';

    return 0;
}