#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int n;
int a[maxn];
int cnt[25];
bitset<25> bit;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        bit = a[i];
        for (int j = 0; j <= 20; ++j)
            if (bit[j]) ++cnt[j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        bit.reset();
        for (int j = 0; j <= 20; ++j)
            if (cnt[j]) {
                bit[j] = 1;
                --cnt[j];
            }
        int ret = bit.to_ulong();
        ans += 1ll * ret * ret;
    }
    cout << ans << '\n';

    return 0;
}