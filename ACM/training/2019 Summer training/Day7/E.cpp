#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, x, y, z, block, num;
int a[maxn], bl[maxn], l[maxn], r[maxn], b[maxn], c[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    block = sqrt(n);
    num = n / block;
    if (n % block) ++num;
    up(i, 0, n - 1) bl[i] = i / block + 1;
    up(i, 1, num) {
        l[i] = (i - 1) * block;
        r[i] = i * block - 1;
    }
    r[num] = n;
    up(i, 0, n - 1) scanf("%d", &a[i]);
    dn(i, n - 1, 0) {
        b[i] = i + a[i];
        c[i] = 1;
        if (b[i] < n && bl[i] == bl[b[i]]) {
            c[i] = c[b[i]] + 1;
            b[i] = b[b[i]];
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        if (x == 1) {
            int ans = 0;
            while (y < n) {
                ans += c[y];
                y = b[y];
            }
            printf("%d\n", ans);
        } else {
            scanf("%d", &z);
            a[y] = z;
            dn(i, r[bl[y]], l[bl[y]]) {
                b[i] = i + a[i];
                c[i] = 1;
                if (b[i] < n && bl[i] == bl[b[i]]) {
                    c[i] = c[b[i]] + 1;
                    b[i] = b[b[i]];
                }
            }
        }
    }

    return 0;
}