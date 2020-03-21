#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll N, K;
ll a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> N >> K;
        ll sum = 0;
        for (int i = 1; i <= N; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % K)
            cout << "-1\n";
        else {
            ll size = sum / K;
            int ans = 0;
            for (int i = 2; i <= N; ++i) {
                if (a[i - 1] % size) {
                    a[i] += a[i - 1];
                    a[i - 1] = 0;
                    ++ans;
                }
            }
            for (int i = 1; i <= N; ++i) {
                ans += max(a[i] / size - 1, 0ll);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}

// 1 1 2 3 6 7
// 2 6 6 6