#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 500;
const int inf = 0x3f3f3f3f;

int n;
int a[(int)1e5 + 5], order[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    up(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    if (a[n] >= a[n - 1] + a[n - 2]) {
        printf("NO\n");
        return 0;
    }
    int center = 1e5 + 5, l = center, r = center;
    bool conv = true;
    order[center] = a[1];
    up(i, 2, n) {
        if (conv)
            order[--l] = a[i];
        else
            order[++r] = a[i];
        conv = !conv;
    }
    printf("YES\n");
    up(i, l, r) printf("%d ", order[i]);
    printf("\n");

    return 0;
}