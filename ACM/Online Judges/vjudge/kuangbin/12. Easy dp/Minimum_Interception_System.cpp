#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, ans;
int h[maxn], dp[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= ans + 1; ++j) {
                if (j <= ans) {
                    if (dp[j] >= h[i]) {
                        dp[j] = h[i];
                        break;
                    }
                } else {
                    dp[j] = h[i];
                    ++ans;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}