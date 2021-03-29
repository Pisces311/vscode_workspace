#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct block {
    int len, num;
} a[40];

int t, n, W;
int w[maxn];

int cal(int x) {
    int cnt = 0;
    while (x != 1) {
        x /= 2;
        cnt += 1;
    }
    return cnt;
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
        cin >> n >> W;
        a[0] = {1, 0};
        for (int i = 1; i <= 30; ++i) a[i] = {a[i - 1].len * 2, 0};
        int x;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            ++a[cal(x)].num;
        }
        int ans = 0;
        while (n) {
            int cur_len = W;
            for (int i = 30; i >= 0; --i) {
                int piece = min(cur_len / a[i].len, a[i].num);
                cur_len -= piece * a[i].len;
                a[i].num -= piece;
                n -= piece;
            }
            ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}