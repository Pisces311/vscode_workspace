#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e4 + 5;

int n, order, num, u, v, top;
pii ans[maxn];
int dfn[maxn], low[maxn];
vector<int> g[maxn];

inline void init() {
    order = top = 0;
    mem(dfn, 0);
    up(i, 0, n - 1) g[i].clear();
}

void tarjan(int u, int pre) {
    low[u] = dfn[u] = order++;
    up(i, 0, (int)g[u].size() - 1) {
        int v = g[u][i];
        if (v == pre) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) ans[top++] = {min(u, v), max(u, v)};
        } else
            low[u] = min(low[u], dfn[v]);
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while (~scan(n)) {
        init();
        up(i, 0, n - 1) {
            scanf("%d (%d)", &u, &num);
            up(i, 0, num - 1) {
                scan(v);
                if (v < u) continue;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        up(i, 0, n - 1) if (!dfn[i]) tarjan(i, -1);
        sort(ans, ans + top);
        printf("%d critical links\n", top);
        up(i, 0, top - 1) printf("%d - %d\n", ans[i].first, ans[i].second);
        printf("\n");
    }

    return 0;
}