#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int t, n;
char cmp[maxn];
map<ll, int> mapa, mapb;
ll a[maxn], b[maxn], c[maxn];

inline void init() {
    mapa.clear();
    mapb.clear();
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        init();
        cin >> n >> (cmp + 1);
        a[1] = 2e5 * 2e5;
        b[1] = 1;
        ll high = a[1] - 2e5, base = 2e5;
        ll delta = 2e5;
        for (int i = 1; i < n; ++i) {
            if (cmp[i] == '<') {
                a[i + 1] = a[i] + 1;
                b[i + 1] = b[i] + delta;
            } else {
                a[i + 1] = high;
                high -= base;
                b[i + 1] = b[i] - 1;
            }
        }
        for (int i = 1; i <= n; ++i) c[i] = a[i];
        sort(c + 1, c + n + 1);
        for (int i = 1; i <= n; ++i) mapa[c[i]] = i;
        for (int i = 1; i <= n; ++i) c[i] = b[i];
        sort(c + 1, c + n + 1);
        for (int i = 1; i <= n; ++i) mapb[c[i]] = i;
        for (int i = 1; i <= n; ++i) cout << mapa[a[i]] << " \n"[i == n];
        for (int i = 1; i <= n; ++i) cout << mapb[b[i]] << " \n"[i == n];
    }

    return 0;
}