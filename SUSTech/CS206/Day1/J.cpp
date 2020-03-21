#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int T, N;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int a = N % 10;
        int tmp = a * a % 10, cnt = 1;
        while (tmp != a) {
            tmp = tmp * a % 10;
            ++cnt;
        }
        int e = N % cnt;
        if (e == 0) e = cnt;
        int ans = pow(a, e);
        ans %= 10;
        printf("%d\n", ans);
    }

    return 0;
}