#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T;
ll a, b, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        if (a > b) swap(a, b);
        if (b > n)
            cout << "0\n";
        else {
            int ans = 0;
            while (true) {
                if (a < b) {
                    a += b;
                    ++ans;
                    if (a > n) break;
                } else {
                    b += a;
                    ++ans;
                    if (b > n) break;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}