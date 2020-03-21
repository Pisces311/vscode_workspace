#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

int n, m;
int vis[maxn], u[maxn], v[maxn];
bool ok = true;
vector<int> g[maxn];

void dfs(int s, int r, int fa) {
    int len = g[s].size();
    vis[s] = r;
    for (int i : g[s]) {
        if (i == fa) continue;
        if (vis[i] == -1)
            dfs(i, r ^ 1, s);
        else if (vis[i] == r)
            ok = false;
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);
    up(i, 1, m) {
        scanf("%d %d", &u[i], &v[i]);
        g[v[i]].push_back(u[i]);
        g[u[i]].push_back(v[i]);
    }
    mem(vis, -1);
    dfs(1, -1, 1);
    if (!ok)
        printf("NO\n");
    else {
        printf("YES\n");
        up(i, 1, m) printf("%d", vis[u[i]] > vis[v[i]]);
    }

    return 0;
}