#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n, order;
int a[maxn], dfn[maxn];
vector<int> g[maxn];
vector<int> q;

inline void init() {
    q.clear();
    up(i, 1, n + 1) g[i].clear();
}

void dfs(int u) {
    dfn[u] = order--;
    for (int i : g[u]) dfs(i);
}

void solve() {
    scanf("%d", &n);
    init();
    up(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] == -1) a[i] = i + 1;
        g[a[i]].push_back(i);
    }
    order = n + 1;
    dfs(n + 1);
    dn(i, n, 1) {
        while (!q.empty() && dfn[q.back()] < dfn[i]) q.pop_back();
        if ((q.empty() && a[i] != n + 1) || (!q.empty() && q.back() != a[i])) {
            printf("-1\n");
            return;
        }
        q.push_back(i);
    }
    up(i, 1, n) printf("%d ", dfn[i]);
    printf("\n");
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) solve();

    return 0;
}