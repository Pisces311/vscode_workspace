#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e2 + 5;

int T, n, m;
int a[maxn][maxn], b[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
        double ans = 0;
        for (int j = 1; j <= m; ++j) {
            int sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += a[i][j];
                ans = max(ans, 1.0 * sum / a[i][j]);
            }
        }
        printf("%.8f\n", ans);
    }

    return 0;
}