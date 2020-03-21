#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int r, s, p;
double dp[maxn][maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &r, &s, &p);
    mem(dp, 0);
    dp[r][s][p] = 1;
    dn(i, r, 0) dn(j, s, 0) dn(k, p, 0) {
        int sum = i * j + j * k + k * i;
        if (j && k) dp[i][j][k - 1] += dp[i][j][k] * (1.0 * j * k / sum);
        if (i && j) dp[i][j - 1][k] += dp[i][j][k] * (1.0 * i * j / sum);
        if (k && i) dp[i - 1][j][k] += dp[i][j][k] * (1.0 * k * i / sum);
    }
    double ansr = 0, anss = 0, ansp = 0;
    up(i, 0, r) ansr += dp[i][0][0];
    up(i, 0, s) anss += dp[0][i][0];
    up(i, 0, p) ansp += dp[0][0][i];
    printf("%.9f %.9f %.9f\n", ansr, anss, ansp);

    return 0;
}