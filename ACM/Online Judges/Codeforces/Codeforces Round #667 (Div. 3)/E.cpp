#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int t, n, k;
int x[maxn], y[maxn], a[maxn];
int Max[maxn][20];

void init(int n) {
    for (int i = 1; i <= n; ++i) Max[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int qmax(int l, int r) {
    int k = (log(double(r - l + 1)) / log((double)2));
    return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) cin >> y[i];
        sort(x + 1, x + n + 1);
        for (int l = 1, r = 1; l <= n; ++l) {
            while (r < n && x[r + 1] <= x[l] + k) ++r;
            a[l] = r - l + 1;
        }
        init(n);
        int ans = 0;
        for (int l = 1, r = 1; l <= n; ++l) {
            while (r < n && x[r + 1] <= x[l] + k) ++r;
            int bound = r + 1;
            int cur = a[l];
            if (bound <= n) cur += qmax(bound, n);
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }

    return 0;
}