#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int q, n, k;
int p[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &k);
        up(i, 1, n) scanf("%d", &p[i]);
        sort(p + 1, p + n + 1);
        if (p[n] - p[1] > 2 * k) {
            printf("-1\n");
            continue;
        }
        if (p[n] - p[1] < k) p[n] = p[1] + k;
        while (p[n] - p[1] > k) {
            p[n] = p[1] + k;
            sort(p + 1, p + n + 1);
        }
        printf("%d\n", p[n]);
    }

    return 0;
}