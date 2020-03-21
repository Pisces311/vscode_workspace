#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

struct package {
    int x, y;
    bool operator<(const package& a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
} p[maxn];

int t, n;

bool check() {
    for (int i = 2; i <= n; ++i)
        if (p[i].y < p[i - 1].y) return false;
    return true;
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
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
        sort(p + 1, p + n + 1);
        if (check()) {
            cout << "YES\n";
            int x = 0, y = 0, ptr = 0;
            while (ptr < n) {
                ++ptr;
                while (x < p[ptr].x) {
                    cout << 'R';
                    ++x;
                }
                while (y < p[ptr].y) {
                    cout << 'U';
                    ++y;
                }
            }
            cout << '\n';
        } else
            cout << "NO\n";
    }

    return 0;
}