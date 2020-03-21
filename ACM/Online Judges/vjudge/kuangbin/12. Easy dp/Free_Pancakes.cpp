#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, x, T;
int dp[maxn][15];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        if (!n) break;
        int ma = -inf;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &x, &T);
            ++dp[T][x];
            ma = max(ma, T);
        }
        for (int i = ma - 1; i >= 0; --i) {
            for (int j = 0; j <= 10; ++j) {
                if (j == 0)
                    dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
                else if (j < 10)
                    dp[i][j] += max(dp[i + 1][j - 1],
                                    max(dp[i + 1][j], dp[i + 1][j + 1]));
                else
                    dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j]);
            }
        }
        printf("%d\n", dp[0][5]);
    }

    return 0;
}