#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 100000 + 5;

int q;
ll n;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &q);
    while (q--) {
        scanf("%lld", &n);
        bool ok = true;
        int cnt = 0;
        while (n != 1) {
            if (n & 1) {
                if (n % 3 == 0)
                    n = (n / 3) * 2;
                else if (n % 5 == 0)
                    n = (n / 5) * 4;
                else {
                    ok = false;
                    break;
                }
            } else
                n = n / 2;
            ++cnt;
        }
        if (ok)
            printf("%d\n", cnt);
        else
            printf("-1\n");
    }

    return 0;
}