#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, X, Y, K;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": ";
        cin >> X >> Y >> K;
        if (X > Y)
            cout << K << '\n';
        else {
            int has = 0, ans = 0, fee = 11 * Y - 9 * X;
            while (K) {
                while (K && has < fee) {
                    --K;
                    has += 11 * X;
                }
                if (K && has >= fee) {
                    --K;
                    has -= fee;
                    ++ans;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}