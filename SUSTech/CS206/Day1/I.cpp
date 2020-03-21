#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
ll sum;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        sum = 1ll * (1 + n) * n / 2;
        printf("%lld\n\n", sum);
    }

    return 0;
}