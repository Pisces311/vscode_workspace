#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int T, M;
int t[maxn], val[maxn], dp[1005];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> M;
    for (int i = 1; i <= M; ++i) cin >> t[i] >> val[i];
    for (int i = 1; i <= M; ++i) {
        for (int j = T; j >= t[i]; --j) {
            dp[j] = max(dp[j], dp[j - t[i]] + val[i]);
        }
    }
    cout << dp[T] << '\n';

    return 0;
}