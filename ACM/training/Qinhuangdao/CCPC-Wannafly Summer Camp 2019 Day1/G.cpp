#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e2 + 5;

int n;
int p[maxn];
char g[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (g[i][k] == '1' && g[k][j] == '1') g[i][j] = '1';
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (g[i][j] == '1' && p[i] > p[j]) swap(p[i], p[j]);
    for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
    printf("\n");

    return 0;
}