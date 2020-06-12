#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, m, x;

bool intersect(int l, int r, int cl, int cr) {
    if (r < cl || l > cr) return false;
    return true;
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
        cin >> n >> x >> m;
        int cl = x, cr = x;
        while (m--) {
            int l, r;
            cin >> l >> r;
            if (intersect(l, r, cl, cr)) {
                cl = min(cl, l);
                cr = max(cr, r);
            }
        }
        cout << cr - cl + 1 << '\n';
    }

    return 0;
}