#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;

int T, n, k, u, v, sz, cnt;
vector<int> g[maxn], color[maxn];
int son[maxn], tmp[maxn], fa[maxn];
bool vis[maxn];

inline void init() {
    sz = n / k;
    up(i, 1, n) {
        tmp[i] = 0;
        vis[i] = false;
        g[i].clear();
        color[i].clear();
    }
    cnt = 0;
}

void dfs(int x, int pre) {
    son[x] = 1;
    up(i, 0, (int)g[x].size() - 1) {
        int v = g[x][i];
        if (v == pre) continue;
        dfs(v, x);
        son[x] += son[v];
    }
    ++tmp[son[x]];
    fa[x] = pre;
    if (son[x] % k == 0) color[son[x]].push_back(x);
}

void _dfs(int x, int pre) {
    if (vis[x]) return;
    vis[x] = true;
    ++cnt;
    printf("%d%c", x, cnt % k == 0 ? '\n' : ' ');
    up(i, 0, (int)g[x].size() - 1) {
        int v = g[x][i];
        if (v == pre) continue;
        _dfs(v, x);
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    scan(T);
    while (T--) {
        scanf("%d %d", &n, &k);
        init();
        up(i, 1, n - 1) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 1);
        int num = 0;
        for (int i = k; i <= n; i += k) num += tmp[i];
        if (num == sz) {
            printf("YES\n");
            for (int i = k; i <= n; i += k) {
                up(j, 0, (int)color[i].size() - 1) {
                    int v = color[i][j];
                    _dfs(v, fa[v]);
                }
            }
        } else
            printf("NO\n");
    }

    return 0;
}