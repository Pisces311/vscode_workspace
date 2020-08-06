#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
ll m;
ll a[maxn];
bool is[maxn];

inline void init() { memset(is + 1, false, sizeof(bool) * n); }

bool solve3() {
    int cnt = 0;
    for (int i = 1; i <= 3; ++i)
        if (a[i] == -1) ++cnt;
    ll sum = accumulate(a + 1, a + 4, 0ll);
    if (!cnt && sum < m) {
        return false;
    } else {
        for (int i = 3; i >= 1; --i) {
            if (a[i] == -1) {
                a[i] = m - (sum + cnt);
                a[i] = max(a[i], 0ll);
                break;
            }
        }
        for (int i = 1; i <= 3; ++i)
            if (a[i] == -1) a[i] = 0;
    }
    return true;
}

int find(int l, int r) {
    for (int i = r; i >= l; --i)
        if (is[i]) return i;
    return -1;
}

bool solve() {
    for (int i = 4; i <= n; ++i) {
        ll cur = a[i - 2] + a[i - 1];
        if (a[i] != -1) cur += a[i];
        if (a[i] == -1) {
            a[i] = m - cur;
            a[i] = max(a[i], 0ll);
        } else if (cur < m) {
            int p = find(i - 2, i);
            if (p == -1) return false;
            a[p] += m - cur;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i)
            if (a[i] == -1) is[i] = true;
        if (solve3() && solve()) {
            cout << accumulate(a + 1, a + n + 1, 0ll) << '\n';
        } else
            cout << "Impossible\n";
    }

    return 0;
}