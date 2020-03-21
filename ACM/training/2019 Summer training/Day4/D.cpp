#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int n, k, c, d;
int g[maxn][maxn], dp[maxn][maxn];
int point[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

int dfs(int x, int y) {
    if (dp[x][y] > 0)
        return dp[x][y];
    else {
        int maxn = 0, sum;
        up(i, 1, 4) {
            up(j, 1, k) {
                int dx = x + (point[0][i - 1]) * j;
                int dy = y + (point[1][i - 1]) * j;
                if (dx >= 1 && dy >= 1 && dx <= n && dy <= n &&
                    g[dx][dy] > g[x][y]) {
                    sum = dfs(dx, dy);
                    maxn = max(sum, maxn);
                }
            }
        }
        dp[x][y] = maxn + g[x][y];
        return dp[x][y];
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d %d", &n, &k)) {
        if (n == -1 && k == -1) return 0;
        mem(dp, 0);
        up(i, 1, n) up(j, 1, n) scanf("%d", &g[i][j]);
        dfs(1, 1);
        printf("%d\n", dp[1][1]);
    }

    return 0;
}