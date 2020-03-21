#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

int M, N;
int AI[maxn];
double g[125][125], dp[maxn][125];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &M)) {
        int R = (M * (M - 1) * (M - 2)) / (3 * 2);
        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= R; ++j) scanf("%lf", &g[i][j]);
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &AI[i]);
            ++AI[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= R; ++i) dp[1][i] = g[i][AI[1]];
        for (int i = 2; i <= N; ++i) {
            double tmp = 0;
            for (int j = 1; j <= R; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] * g[j][AI[i]]);
                tmp = max(tmp, dp[i - 1][j] * g[AI[i - 1]][AI[i]]);
            }
            dp[i][AI[i - 1]] = max(dp[i][AI[i - 1]], tmp);
        }
        printf("%.8f\n", *max_element(dp[N] + 1, dp[N] + R + 1));
    }

    return 0;
}