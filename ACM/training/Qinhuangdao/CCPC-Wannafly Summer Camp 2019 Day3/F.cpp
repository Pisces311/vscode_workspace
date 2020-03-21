#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

int n, a, b;
ll dp[110][10010];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= b; k++) {
                if (j - k < 0) break;
                dp[i][j] += dp[i - 1][j - k] % mod;
                dp[i][j] %= mod;
            }
        }
    }
    ll cd = 0;
    for (int i = 0; i <= b; i++) {
        if (i * a <= n) cd++;
    }
    printf("%lld\n", dp[a][n] - cd);

    return 0;
}