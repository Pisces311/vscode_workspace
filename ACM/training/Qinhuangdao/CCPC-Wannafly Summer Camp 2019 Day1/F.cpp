#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int n, m, ans = 0;
int val[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        ans += min(val[u], val[v]);
    }
    printf("%d\n", ans);

    return 0;
}