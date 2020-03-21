#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

int n, x, y;
char num[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &n, &x, &y);
    scanf("%s", num + 1);
    int cnt = 0;
    dn(i, n, n - x + 1) {
        if (num[i] == '0' && i == n - y) ++cnt;
        if (num[i] == '1' && i != n - y) ++cnt;
    }
    printf("%d\n", cnt);

    return 0;
}