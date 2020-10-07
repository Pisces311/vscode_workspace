#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e3 + 5;

int N, M, K;
int dp[maxn][maxn], up[maxn];

inline void init() {
    memset(dp, 0, sizeof(dp));
    memset(up, 0, sizeof(up));
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
        cin >> N >> M >> K;
        init();
        for (int i = 1; i <= M; ++i) {
            int l, r;
            cin >> l >> r;
            for (int j = l; j <= r; ++j) up[j] = max(up[j], r);
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= K; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (up[i]) {
                    dp[up[i]][j] =
                        max(dp[up[i]][j], dp[i - 1][j - 1] + up[i] - i + 1);
                }
            }
        }
        cout << "Case #" << cas << ": " << dp[N][K] << '\n';
    }

    return 0;
}