#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v;
} edge[maxm];

int n, m, cnt = 0;
int deg[maxn], after[maxn];
bool ok[maxm];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    up(i, 1, m) {
        scanf("%d %d", &edge[i].u, &edge[i].v);
        ++deg[edge[i].u];
        ++deg[edge[i].v];
    }
    random_shuffle(edge + 1, edge + m + 1);
    up(i, 1, n) after[i] = deg[i];
    up(i, 1, m) {
        int u = edge[i].u, v = edge[i].v;
        if (after[u] - 1 >= (deg[u] + 1) >> 1 &&
            after[v] - 1 >= (deg[v] + 1) >> 1) {
            ok[i] = true;
            --after[u];
            --after[v];
            ++cnt;
        }
    }
    printf("%d\n", m - cnt);
    up(i, 1, m) if (!ok[i]) printf("%d %d\n", edge[i].u, edge[i].v);

    return 0;
}