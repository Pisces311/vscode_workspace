#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e7 + 5;

int n, m;
unsigned x, y, z;
unsigned a[maxn], ans[105];

struct query {
    int x;
    int id;
    bool operator<(const query& a) const { return x < a.x; }
} q[105];

unsigned rng61() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cas = 0;
    while (cin >> n >> m >> x >> y >> z) {
        for (int i = 1; i <= n; ++i) a[i] = rng61();
        cout << "Case #" << ++cas << ": ";
        for (int i = 1; i <= m; ++i) cin >> q[i].x, q[i].id = i;
        sort(q + 1, q + m + 1);
        int bound = n;
        for (int i = m; i >= 1; i--) {
            nth_element(a + 1, a + q[i].x + 1, a + bound + 1);
            bound = q[i].x;
            ans[q[i].id] = a[q[i].x + 1];
        }
        for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
    }

    return 0;
}