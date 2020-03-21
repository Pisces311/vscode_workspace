#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int m, n;
int a[maxn], dp[maxn], tmp[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &m, &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        memset(tmp, 0, sizeof(tmp));
        int ma;
        for (int i = 1; i <= m; ++i) {
            ma = -inf;
            for (int j = i; j <= n; ++j) {
                dp[j] = max(tmp[j - 1], dp[j - 1]) + a[j];
                tmp[j - 1] = ma;
                ma = max(ma, dp[j]);
            }
        }
        printf("%d\n", ma);
    }

    return 0;
}