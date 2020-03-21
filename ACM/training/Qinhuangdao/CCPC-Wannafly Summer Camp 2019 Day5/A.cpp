#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, m;
int s[maxn], p[maxn];
ll tmp[maxn];
ll Min[maxn][20];

void init() {
    for (int i = 1; i <= n; i++) Min[i][0] = tmp[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
        }
    }
}

ll qmin(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d %d", &s[i], &p[i]);
        for (int i = 1; i <= n; ++i) tmp[i] = 1ll * s[i] * p[i];
        init();
        for (int i = 1; i <= m; ++i) {
            int q;
            scanf("%d", &q);
            int pos = lower_bound(s + 1, s + n + 1, q) - s;
            if (s[pos] > q) --pos;
            if (pos == n + 1)
                printf("%lld\n", 1ll * q * p[n]);
            else {
                ll ans = LLONG_MAX;
                ans = min(ans, 1ll * q * p[pos]);
                if (pos < n) ans = min(ans, qmin(pos + 1, n));
                printf("%lld\n", ans);
            }
        }
    }

    return 0;
}