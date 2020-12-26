#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    int w, res;
} a[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int score, tot = 0;
        for (int i = 1; i <= 4; ++i) {
            cin >> score;
            tot += score;
            a[i].res = 30 - score;
        }
        for (int i = 1; i <= 4; ++i) cin >> a[i].w;
        sort(a + 1, a + 5, [](node &a, node &b) { return a.w < b.w; });
        int ans = 0, i = 1;
        while (tot < 100) {
            if (a[i].res) {
                ++tot;
                --a[i].res;
                ans += a[i].w;
            } else
                ++i;
        }
        cout << ans << '\n';
    }

    return 0;
}