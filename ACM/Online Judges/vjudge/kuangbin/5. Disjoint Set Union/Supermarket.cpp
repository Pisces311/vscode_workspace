#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct prod {
    int w, ddl;
    bool operator<(const prod& a) const { return w > a.w; }
} p[maxn];

int n, ans;
int fa[maxn];

inline void init() {
    ans = 0;
    up(i, 1, maxn) fa[i] = i;
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        init();
        up(i, 1, n) scanf("%d %d", &p[i].w, &p[i].ddl);
        sort(p + 1, p + n + 1);
        up(i, 1, n) {
            int ddl = p[i].ddl, x = find(ddl);
            if (x == 0) continue;
            ans += p[i].w;
            fa[x] = x - 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}