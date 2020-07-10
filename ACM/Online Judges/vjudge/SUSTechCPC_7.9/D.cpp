#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 6e2 + 5;

struct beam {
    int x, y;
    beam() {}
    beam(int a, int b) : x(a), y(b) {}
    bool operator<(const beam &a) const {
        return 1ll * x * a.y - 1ll * y * a.x < 0;
    }
    bool operator==(const beam &a) const {
        return 1ll * x * a.y - 1ll * y * a.x == 0;
    }
} a[maxn];

int T, n;
int l[maxn], r[maxn], w[maxn], h[maxn];
ll dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> h[i] >> l[i] >> r[i] >> w[i];
            a[2 * i - 1] = beam(l[i], h[i]);
            a[2 * i] = beam(r[i], h[i]);
        }
        sort(a + 1, a + 2 * n + 1);
        int cnt = unique(a + 1, a + 2 * n + 1) - (a + 1);
        for (int i = 1; i <= n; ++i) {
            l[i] = lower_bound(a + 1, a + 1 + cnt, beam(l[i], h[i])) - a;
            r[i] = lower_bound(a + 1, a + 1 + cnt, beam(r[i], h[i])) - a;
        }
        memset(dp, 0, sizeof(dp));
        for (int len = 1; len <= cnt; ++len) {
            for (int i = 1; i + len - 1 <= cnt; ++i) {
                int j = i + len - 1;
                int L = 0, R = 0, ma = -1;
                for (int k = 1; k <= n; ++k) {
                    if (i <= l[k] && r[k] <= j && w[k] > ma) {
                        ma = w[k];
                        L = l[k];
                        R = r[k];
                    }
                }
                if (ma != -1) {
                    dp[i][j] = LLONG_MAX;
                    for (int k = L; k <= R; ++k)
                        dp[i][j] =
                            min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + ma);
                }
            }
        }
        cout << dp[1][cnt] << '\n';
    }

    return 0;
}