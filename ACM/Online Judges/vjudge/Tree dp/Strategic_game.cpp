#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1.5e3 + 5;

int n;
int dp[maxn][2], fa[maxn];
vector<int> g[maxn];

void dfs(int x) {
    int sum = 0;
    dp[x][1] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        int v = g[x][i];
        dfs(v);
        dp[x][1] += min(dp[v][0], dp[v][1]);
        dp[x][0] += dp[v][1];
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        memset(fa, 0, sizeof(fa));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            int u, k, v;
            scanf("%d:(%d)", &u, &k);
            ++u;
            while (k--) {
                scanf("%d", &v);
                ++v;
                g[u].push_back(v);
                fa[v] = u;
            }
        }
        int root;
        for (int i = 1; i <= n; ++i)
            if (!fa[i]) root = i;
        dfs(root);
        printf("%d\n", min(dp[root][0], dp[root][1]));
    }

    return 0;
}