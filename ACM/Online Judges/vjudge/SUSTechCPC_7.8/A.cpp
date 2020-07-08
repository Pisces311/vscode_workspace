#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e7 + 5;

int T, n, m, k;
int a[maxn];
ll p, q, r, MOD;
ll que[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> m >> k >> p >> q >> r >> MOD;
        for (int i = 1; i <= k; ++i) cin >> a[i];
        for (int i = k + 1; i <= n; ++i)
            a[i] = (p * a[i - 1] + q * i + r) % MOD;
        int h = 1, t = 0;
        ll A = 0, B = 0;
        for (int i = n; i >= 1; --i) {
            while (t >= h && a[i] >= a[que[t]]) --t;
            que[++t] = i;
            if (que[h] >= i + m) ++h;
            if (i <= n - m + 1) {
                A += i ^ a[que[h]];
                B += i ^ (t - h + 1);
            }
        }
        cout << A << ' ' << B << '\n';
    }

    return 0;
}