#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, l, r;
int a[maxn], pre[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    up(i, 1, n) scanf("%d", &a[i]);
    up(i, 1, n) pre[i] = pre[i - 1] + a[i];
    scanf("%d", &m);
    up(i, 1, m) {
        scanf("%d %d", &l, &r);
        --l;
        printf("%d\n", (pre[r] - pre[l]) / 10);
    }

    return 0;
}