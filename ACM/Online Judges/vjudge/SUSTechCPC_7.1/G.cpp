#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;

int T, N;
int m[maxn];
double P, p[maxn];
double dp[maxn * maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> P >> N;
        for (int i = 1; i <= N; ++i) cin >> m[i] >> p[i];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= N; ++i)
            for (int j = 1e4; j >= m[i]; --j)
                dp[j] = max(dp[j], dp[j - m[i]] * (1 - p[i]));
        for (int i = 1e4; i >= 0; --i) {
            if (1 - dp[i] < P) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}