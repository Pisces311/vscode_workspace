#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

ll T, n, k, q;

ll frac(ll n) {
    ll ret = 1;
    do {
        ret = ret * n % q;
    } while (--n);
    return ret;
}

ll case1() {
    ll pre = frac(k);
    ll suf = ((n - k - 1) * (n - k - 1) % q + 1) % q;
    return pre * suf % q;
}

ll case2() {
    ll pre = frac(k);
    ll suf = ((k + 1) * (n - k) % q - 1 + q) % q;
    return pre * suf % q;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    ll cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> n >> k >> q;
        k = min(n, k);
        ll ans = (case1() + case2()) % q;
        cout << ans << '\n';
    }

    return 0;
}