#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, k, a, ans = inf;
int v[maxn], u[maxn], l[maxn];
bool vis[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) scanf("%d %d %d", &u[i], &v[i], &l[i]);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &a);
        vis[a] = true;
    }
    for (int i = 1; i <= m; i++)
        if (vis[u[i]] && !vis[v[i]] || !vis[u[i]] && vis[v[i]])
            ans = min(ans, l[i]);
    if (ans != inf)
        printf("%d\n", ans);
    else
        puts("-1");

    return 0;
}