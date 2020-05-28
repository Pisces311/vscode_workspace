#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, h, c, t;

double cal(int x) { return fabs((1.0 * x * (h + c) + h) / (2 * x + 1) - t); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> h >> c >> t;
        if (2 * t <= h + c)
            cout << "2\n";
        else {
            int l = 0, r = 1e9;
            while (l < r) {
                int mid = (l + r) >> 1;
                ll res = (1ll * mid * (h + c) + h);
                if (res <= 1ll * t * (2 * mid + 1))
                    r = mid;
                else if (l == mid)
                    ++l;
                else
                    l = mid;
            }
            double ans1 = cal(l), ans2 = cal(l + 1), ans3 = cal(l - 1);
            if (ans3 <= ans1 && ans3 <= ans2)
                l = 2 * l - 1;
            else if (ans2 <= ans1 && ans2 <= ans3)
                l = 2 * l + 3;
            else
                l = 2 * l + 1;
            cout << l << '\n';
        }
    }

    return 0;
}
