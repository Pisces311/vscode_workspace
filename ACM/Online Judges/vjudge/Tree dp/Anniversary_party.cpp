#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 6e3 + 5;

int N, u, v;
int a[maxn], fa[maxn], dp[maxn][2];
vector<int> g[maxn];

void dfs(int x) {
    dp[x][1] = a[x];
    for (int i = 0; i < g[x].size(); ++i) {
        int v = g[x][i];
        dfs(v);
        dp[x][1] += dp[v][0];
        dp[x][0] += max(dp[v][0], dp[v][1]);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
    while (scanf("%d %d", &v, &u) && u + v) {
        g[u].push_back(v);
        fa[v] = u;
    }
    int root;
    for (int i = 1; i <= N; ++i)
        if (!fa[i]) root = i;
    dfs(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));

    return 0;
}