#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

ll x, y, z;
ll ans = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%lld %lld %lld", &x, &y, &z);
    ans += x / z;
    x %= z;
    ans += y / z;
    y %= z;
    if (x >= y) {
        x += y;
        ans += x / z;
        x %= z;
        printf("%lld %lld", ans, y - x >= 0 ? y - x : 0);
    } else {
        y += x;
        ans += y / z;
        y %= z;
        printf("%lld %lld", ans, x - y >= 0 ? x - y : 0);
    }

    return 0;
}