#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll ans = 0;
    int cnt1 = 0, cnt_1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= 1) {
            ++cnt1;
            ans += a[i] - 1;
        } else if (a[i] <= -1) {
            ++cnt_1;
            ans += -1 - a[i];
        } else
            ++cnt0;
    }
    if (cnt_1 & 1) {
        if (cnt0)
            ans += cnt0;
        else if (cnt_1)
            ans += 2;
    } else {
        if (cnt0) ans += cnt0;
    }
    cout << ans << '\n';

    return 0;
}