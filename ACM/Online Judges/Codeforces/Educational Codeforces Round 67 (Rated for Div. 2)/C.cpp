#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct query {
    int l, r;
} q[maxn];

int n, m, t, l, r, tot = 0;
int num[maxn], fa[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    up(i, 1, n) fa[i] = i;
    up(i, 1, m) {
        scanf("%d %d %d", &t, &l, &r);
        if (t)
            up(i, l, r) fa[i] = fa[l];
        else
            q[++tot] = {l, r};
    }
    up(i, 1, tot) {
        int x = find(q[i].l), y = find(q[i].r);
        if (x == y) {
            printf("NO\n");
            return 0;
        }
    }
    num[0] = maxn;
    up(i, 1, n) {
        if (fa[i] == i)
            num[i] = num[i - 1] - 1;
        else
            num[i] = num[i - 1];
    }
    printf("YES\n");
    up(i, 1, n) printf("%d ", num[i]);
    printf("\n");

    return 0;
}