#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n, u, v;
int deg[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    up(i, 1, n - 1) {
        scanf("%d %d", &u, &v);
        ++deg[u];
        ++deg[v];
    }
    bool ok = true;
    up(i, 1, n) if (deg[i] == 2) {
        ok = false;
        break;
    }
    if (ok)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}