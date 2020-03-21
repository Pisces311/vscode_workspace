#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, k;
int a[maxn];
ll dp[maxn][12], ans = 0;

inline void init() {
    for (int i = 1; i <= m; ++i) dp[0][i] = -inf;
}

void solve() {
    init();
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        dp[i][1] = max(0ll, dp[i - 1][m]);
        dp[i][1] += a[i] - k;
        for (int j = 1; j <= m - 1; ++j) {
            dp[i][j + 1] = dp[i - 1][j + 1 - 1] + a[i];
            if (ans < dp[i][j + 1]) ans = dp[i][j + 1];
        }
    }
    for (int i = 1; i <= n; ++i)
        if (ans < dp[i][1]) ans = dp[i][1];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    solve();
    printf("%lld\n", ans);

    return 0;
}