#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    int l, r;
    bool operator<(const node& a) const {
        if (l > r) return a.l > a.r ? r < a.r : true;
        if (l <= r) return a.l <= a.r ? l > a.l : false;
    }
} a[maxn];

int T, n;
string s[maxn];

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
        for (int i = 1; i <= n; ++i) cin >> s[i];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int lcnt = 0, rcnt = 0;
            for (char ch : s[i]) {
                if (ch == '(') {
                    ++lcnt;
                } else {
                    if (lcnt) {
                        --lcnt;
                        ans += 2;
                    } else
                        ++rcnt;
                }
            }
            a[i] = {lcnt, rcnt};
        }
        sort(a + 1, a + n + 1);
        int tot = 0;
        for (int i = 1; i <= n; ++i) {
            if (tot > a[i].r) {
                ans += 2 * a[i].r;
                tot -= a[i].r;
            } else {
                ans += 2 * tot;
                tot = 0;
            }
            tot += a[i].l;
        }
        cout << ans << '\n';
    }

    return 0;
}