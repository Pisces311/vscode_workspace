#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e3 + 5;

int N, M;
int a[maxn][maxn], dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    up(i, 1, N) up(j, 1, M) scanf("%d", &a[i][j]);
    up(i, 1, N) up(j, 1, M) dp[i][j] = -100005;
    up(i, 1, M) dp[1][i] = a[1][i];
    up(i, 2, N) up(j, i, M) up(k, i - 1, j - 1) {
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
    }
    printf("%d\n", *max_element(dp[N] + 1, dp[N] + M + 1));

    return 0;
}