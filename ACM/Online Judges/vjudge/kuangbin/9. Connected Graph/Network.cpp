#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

int N, u, v, order, ans;
char opr;
bool cut[maxn];
int dfn[maxn], low[maxn];
vector<int> g[maxn];

inline void init() {
    order = ans = 0;
    up(i, 1, N) g[i].clear();
    mem(dfn, 0);
    mem(low, 0);
    mem(cut, false);
}

void tarjan(int x, int pre) {
    low[x] = dfn[x] = ++order;
    int son = 0;
    up(i, 0, (int)g[x].size() - 1) {
        int v = g[x][i];
        if (v == pre) continue;
        if (!dfn[v]) {
            ++son;
            tarjan(v, x);
            low[x] = min(low[x], low[v]);
            if (pre != -1 && low[v] >= dfn[x]) cut[x] = true;
        } else
            low[x] = min(low[x], dfn[v]);
    }
    if (pre == -1 && son > 1) cut[x] = true;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while (scan(N) && N) {
        init();
        while (scan(u) && u) {
            while (scanf("%d%c", &v, &opr)) {
                g[u].push_back(v);
                g[v].push_back(u);
                if (opr == '\n') break;
            }
        }
        up(i, 1, N) if (!dfn[i]) tarjan(i, -1);
        up(i, 1, N) if (cut[i])++ ans;
        print(ans);
    }

    return 0;
}