#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

struct soldier {
    ll hp, atk;
    bool operator<(const soldier& a) const { return hp - atk > a.hp - a.atk; }
} a[maxn];

int n, p, q;
ll sum = 0;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].hp >> a[i].atk;
        sum += a[i].atk;
    }
    sort(a + 1, a + n + 1);
    q = min(n, q);
    for (int i = 1; i <= q; ++i)
        if (a[i].hp > a[i].atk) sum += a[i].hp - a[i].atk;
    ll ans = sum;
    if (q) {
        for (int i = 1; i <= q; ++i) {
            ll tmp = sum, cur = a[i].hp << p;
            if (cur > a[i].atk)
                tmp += cur - (a[i].hp > a[i].atk ? a[i].hp : a[i].atk);
            ans = max(tmp, ans);
        }
        if (a[q].hp > a[q].atk) sum -= a[q].hp - a[q].atk;
        for (int i = q + 1; i <= n; ++i) {
            ll tmp = sum, cur = a[i].hp << p;
            if (cur > a[i].atk) tmp += cur - a[i].atk;
            ans = max(tmp, ans);
        }
    }
    cout << ans << '\n';

    return 0;
}