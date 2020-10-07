#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int T, N;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            ans += a[i] + (a[i] + 9) / 10;
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}