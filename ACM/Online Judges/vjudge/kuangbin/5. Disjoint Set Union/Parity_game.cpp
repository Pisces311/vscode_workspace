#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int x, y, val;
} a[maxn];

int N, M, cnt = 0, n;
char str[8];
int fa[maxn], val[maxn], dc[maxn];

int find(int x) {
    if (x == fa[x])
        return x;
    else {
        int root = find(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &M);
    up(i, 0, M - 1) {
        scanf("%d %d %s", &a[i].x, &a[i].y, str + 1);
        --a[i].x;
        a[i].val = str[1] == 'o' ? 1 : 0;
        dc[cnt++] = a[i].x;
        dc[cnt++] = a[i].y;
    }
    sort(dc, dc + cnt);
    n = unique(dc, dc + cnt) - dc;
    up(i, 0, n) {
        fa[i] = i;
        val[i] = 0;
    }
    int i;
    for (i = 0; i < M; i++) {
        int nx = lower_bound(dc, dc + n, a[i].x) - dc;
        int ny = lower_bound(dc, dc + n, a[i].y) - dc;
        int x = find(nx), y = find(ny);
        if (x == y) {
            if ((val[nx] + val[ny] + 2) % 2 != a[i].val) break;
        } else {
            fa[y] = x;
            val[y] = (val[nx] - val[ny] + 2 + a[i].val) % 2;
        }
    }
    printf("%d\n", i);

    return 0;
}