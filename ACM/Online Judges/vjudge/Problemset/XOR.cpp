#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, q, k;
ll d[60];

void insert(ll val) {
    for (ll i = 59; i >= 0; --i) {
        if (val & 1ll << i) {
            if (d[i])
                val ^= d[i];
            else {
                d[i] = val;
                break;
            }
        }
    }
}

bool check(ll val) {
    for (ll i = 59; i >= 0; --i) {
        if (val & 1ll << i) {
            if (d[i])
                val ^= d[i];
            else
                break;
        }
    }
    return val > 0;
}

ll qmax() {
    ll ans = 0;
    for (ll i = 59; i >= 0; --i) ans = max(ans, ans ^ d[i]);
    return ans;
}

ll qmin() {
    for (int i = 0; i <= 59; ++i)
        if (d[i]) return d[i];
    return 0;
}

void rebuild() {
    for (int i = 59; i >= 0; --i)
        for (int j = i - 1; j >= 0; --j)
            if (d[i] & 1ll << j) d[i] ^= d[j];
}

ll Kth(ll k) {
    rebuild();
    int cnt = 0;
    for (int i = 0; i <= 59; i++)
        if (d[i]) ++cnt;
    if (cnt < n && k == 1) return 0;  //最小异或和为0的情况
    if (cnt < n) --k;
    if (k >= (1ll << cnt)) return -1;  //不存在第k小异或和
    ll ans = 0;
    for (int i = 0; i <= 59; ++i)
        if (d[i]) {
            if (k & 1) ans ^= d[i];
            k >>= 1;
        }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ':' << endl;
        memset(d, 0, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            ll a;
            cin >> a;
            insert(a);
        }
        cin >> q;
        while (q--) {
            cin >> k;
            cout << Kth(k) << endl;
        }
    }

    return 0;
}