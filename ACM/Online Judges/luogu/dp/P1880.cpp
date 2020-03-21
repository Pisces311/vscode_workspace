#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e2 + 5;
const int inf = 0x3f3f3f3f;

int N;
int a[maxn], sum[maxn];
int dp[maxn][maxn], dp2[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        a[i + N] = a[i];
    }
    for (int i = 1; i <= 2 * N; ++i) sum[i] = sum[i - 1] + a[i];
    for (int l = 2; l <= N; ++l) {
        for (int i = 1; i + l - 1 <= 2 * N; ++i) {
            int j = i + l - 1;
            dp2[i][j] = inf;
            for (int k = i; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k + 1][j]);
            }
            dp[i][j] += sum[j] - sum[i - 1];
            dp2[i][j] += sum[j] - sum[i - 1];
        }
    }
    int Min = inf, Max = 0;
    for (int i = 1; i <= N; ++i) {
        Max = max(Max, dp[i][i + N - 1]);
        Min = min(Min, dp2[i][i + N - 1]);
    }
    cout << Min << '\n' << Max << '\n';

    return 0;
}