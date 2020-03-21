#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int l, dir;
} edge[maxn];

int n;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    up(i, 1, n) scanf("%d %d", &edge[i].l, &edge[i].dir);
    int xmin = 0, xmax = 1, ymin = 0, ymax = 0, dir = 2;
    int x = 1, y = 0;
    printf("1 ");
    up(i, 1, n) {
        if (edge[i].dir == 1) {
            dir -= 1;
            if (dir == 0) dir = 4;
        } else if (edge[i].dir == -1) {
            dir += 1;
            if (dir == 5) dir = 1;
        } else
            break;
        if (dir == 1) {
            ymax += 1;
            printf("%d ", ymax - y);
            y = ymax;
        } else if (dir == 2) {
            xmax += 1;
            printf("%d ", xmax - x);
            x = xmax;
        } else if (dir == 3) {
            ymin -= 1;
            printf("%d ", y - ymin);
            y = ymin;
        } else {
            xmin -= 1;
            printf("%d ", x - xmin);
            x = xmin;
        }
    }
    printf("\n");

    return 0;
}