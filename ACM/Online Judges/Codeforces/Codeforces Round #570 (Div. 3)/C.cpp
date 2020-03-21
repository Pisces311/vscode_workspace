#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int q, n;
ll k, a, b;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &q);
    while (q--) {
        scanf("%lld %d %lld %lld", &k, &n, &a, &b);
        if (k <= n * b) {
            printf("-1\n");
            continue;
        }
        int l = 0, r = n, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (k <= mid * a + (n - mid) * b)
                r = mid - 1;
            else {
                ans = mid;
                l = mid + 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}