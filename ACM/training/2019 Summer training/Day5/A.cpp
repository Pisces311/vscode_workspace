#include <limits.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) && n) {
        up(i, 1, n) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int ans = INT_MAX;
        dn(i, n, 1) {
            dn(j, n, 1) if (i != j) {
                int sum = a[i] - a[j];
                int l = 1, r = j - 1;
                while (l < r) {
                    if (a[l] + a[r] == sum) {
                        ans = a[i];
                        break;
                    } else if (a[l] + a[r] > sum)
                        --r;
                    else
                        ++l;
                }
                if (ans != INT_MAX) break;
            }
            if (ans != INT_MAX) break;
        }
        if (ans == INT_MAX)
            printf("no solution\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}