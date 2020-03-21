#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;

int t, n;
char str[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", str + 1);
        int sz = 0;
        up(i, 1, n) {
            if (str[i] == '8') {
                sz = n - i + 1;
                break;
            }
        }
        if (sz >= 11)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}