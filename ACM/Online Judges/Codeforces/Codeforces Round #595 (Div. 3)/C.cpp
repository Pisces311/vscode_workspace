#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e3 + 5;

int q, pos;
ll n;
int a[maxn];

inline void init() {
    for (int i = 1; i <= 4e3; ++i) a[i] = 0;
}

inline void toThree() {
    ll tmp = n;
    pos = 0;
    while (tmp) {
        a[pos++] = tmp % 3;
        tmp /= 3;
    }
}

inline void clear(int last) {
    for (int i = 0; i <= last; ++i) a[i] = 0;
}

void solve() {
    init();
    cin >> n;
    toThree();
    int last = -1;
    for (int i = 0; i < pos; ++i)
        if (a[i] == 2) last = i;
    if (last != -1) {
        clear(last);
        for (int i = last + 1; i <= pos + 1; ++i) {
            if (a[i] == 1)
                a[i] = 0;
            else if (a[i] == 0) {
                a[i] = 1;
                break;
            }
        }
    }
    ll ans = 0;
    for (int i = pos + 1; i >= 0; --i) {
        ans *= 3;
        ans += a[i];
    }
    cout << ans << '\n';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) solve();

    return 0;
}
