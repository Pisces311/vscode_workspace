#include <stdio.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e3 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int t, n, m, u, v;
int fa[maxn], val[maxn];
bool ok;

inline void init() {
    ok = true;
    up(i, 1, n) {
        fa[i] = i;
        val[i] = 0;
    }
}

int find(int x) {
    if (x == fa[x]) return x;
    int root = find(fa[x]);
    val[x] = (val[x] + val[fa[x]]) % 2;
    return fa[x] = root;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    up(case_num, 1, t) {
        scanf("%d %d", &n, &m);
        init();
        up(i, 1, m) {
            scanf("%d %d", &u, &v);
            int x = find(u), y = find(v);
            if (x != y) {
                fa[x] = y;
                val[x] = (val[v] - val[u] + 1) % 2;
            } else if (val[u] - val[v] == 0)
                ok = false;
        }
        if (ok)
            printf("Scenario #%d:\nNo suspicious bugs found!\n", case_num);
        else
            printf("Scenario #%d:\nSuspicious bugs found!\n", case_num);
        printf("\n");
    }

    return 0;
}