#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int x, y, tp;
    bool operator<(const node &p) const { return x < p.x; }
} t[maxn];

int n, m, L, U, x, y, tot = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    scanf("%d", &L);
    up(i, 1, n) {
        scanf("%d %d", &x, &y);
        t[++tot] = {x, y, 0};
    }
    scanf("%d", &U);
    up(i, 1, m) {
        scanf("%d %d", &x, &y);
        t[++tot] = {x, y, 1};
    }
    sort(t + 1, t + tot + 1);
    ll sum = 0, lx = -1, anx = 0, any = 0;
    for (int i = 1, pre = 0, pos, flag; i <= tot; pre = pos) {
        pos = t[i].x;
        if (L < U)
            sum += 1ll * (pos - pre) * (U - L), flag = 0;
        else
            flag = 1;
        for (; t[i].x == pos && i <= tot; i++) {
            if (t[i].tp == 0)
                L = t[i].y;
            else
                U = t[i].y;
        }
        if (flag && L < U) lx = pos;
        if (!flag && L >= U) {
            if (lx >= 0) {
                anx++;
                any += sum;
            }
            sum = 0;
            lx = pos;
        }
    }
    printf("%lld %lld\n", anx, any);

    return 0;
}