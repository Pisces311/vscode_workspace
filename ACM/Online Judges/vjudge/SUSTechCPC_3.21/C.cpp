#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

int N, M;
int D[maxn];
int dp[maxn][505];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> D[i];
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= min(i, M); ++j) {
            dp[i][j] = dp[i - 1][j - 1] + D[i];
            dp[i][0] = max(dp[i][0], dp[i - j][j]);
        }
    }
    cout << dp[N][0] << '\n';

    return 0;
}