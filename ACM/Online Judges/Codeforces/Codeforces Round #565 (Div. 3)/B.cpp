#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 100 + 5;

int t, n;
int a, quo[4];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = 0;
        mem(quo, 0);
        up(i, 1, n) {
            scanf("%d", &a);
            ++quo[a % 3];
        }
        ans += quo[0];
        if (quo[1] >= quo[2]) {
            quo[1] -= quo[2];
            ans += quo[2];
            ans += quo[1] / 3;
        } else {
            quo[2] -= quo[1];
            ans += quo[1];
            ans += quo[2] / 3;
        }
        printf("%d\n", ans);
    }

    return 0;
}