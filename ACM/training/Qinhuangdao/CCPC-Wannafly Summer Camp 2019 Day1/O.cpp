#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n, m, cnt1 = 0, cnt2 = 0;
int col[maxn];
vector<int> g[maxn];
bool ok = true;

void dfs(int x, int pre, int c) {
    col[x] = c;
    if (c == 1)
        ++cnt1;
    else
        ++cnt2;
    for (int i = 0; i < g[x].size(); ++i) {
        int v = g[x][i];
        if (v == pre) continue;
        if (!col[v])
            dfs(v, x, c == 1 ? 2 : 1);
        else if (col[v] == c)
            ok = false;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!col[i]) {
            dfs(i, -1, 1);
            if (!ok) return !printf("-1\n");
        }
    printf("%d\n", cnt1);
    for (int i = 1; i <= n; ++i)
        if (col[i] == 1) printf("%d ", i);
    printf("\n%d\n", cnt2);
    for (int i = 1; i <= n; ++i)
        if (col[i] == 2) printf("%d ", i);

    return 0;
}