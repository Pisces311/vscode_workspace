#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct node {
    int val, id;
    bool operator<(const node& a) const { return val < a.val; }
} c[maxn << 1];

int n, p;
int a[maxn], b[maxn];
int cnt[maxn];

inline void init() {
    fill(cnt + 1, cnt + n + 1, 0);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> n >> p;
        init();
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        for (int i = 1; i <= n; ++i) c[i] = {a[i], i};
        for (int i = 1; i <= n; ++i) c[n + i] = {b[i], i};
        sort(c + 1, c + 2 * n + 1);
        int ans = 0, cur = 0;
        for (int i = 2 * n, pos = i + 1; i; --i) {
            int score = (c[i].val * p + 99) / 100;
            while (pos > 2 && c[pos - 1].val >= score) {
                --pos;
                if (++cnt[c[pos].id] == 1) ++cur;
            }
            ans = max(ans, cur);
            if (!--cnt[c[i].id]) --cur;
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}