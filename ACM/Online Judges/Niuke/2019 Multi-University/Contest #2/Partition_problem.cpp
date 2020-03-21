#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e1 + 5;

int n;
int g[maxn][maxn];
bool stay[maxn];
long long ans = 0;

void dfs(int cur, int tot, long long sum) {
    if (tot == n) {
        ans = max(ans, sum);
        return;
    }
    for (int i = cur + 1; i <= n + tot; ++i) {
        stay[i] = true;
        long long add = 0;
        for (int j = 1; j <= 2 * n; ++j) {
            if (stay[j])
                add -= g[i][j];
            else
                add += g[i][j];
        }
        dfs(i, tot + 1, sum + add);
        stay[i] = false;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i)
        for (int j = 1; j <= 2 * n; ++j) scanf("%d", &g[i][j]);
    dfs(0, 0, 0);
    printf("%lld\n", ans);

    return 0;
}