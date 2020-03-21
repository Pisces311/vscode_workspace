#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e4 + 5;

int N, K, type, u, v, ans;
int a[maxn], fa[maxn], val[maxn];

inline void init() {
    ans = 0;
    up(i, 1, N) {
        fa[i] = i;
        val[i] = 0;
    }
}

inline int find(int x) {
    if (x == fa[x])
        return x;
    else {
        int root = find(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &K);
    init();
    up(i, 1, K) {
        scanf("%d %d %d", &type, &u, &v);
        if (u > N || v > N || (u == v && type == 2)) {
            ++ans;
            continue;
        }
        int r1 = find(u), r2 = find(v);
        if (type == 1) {
            if (r1 != r2) {
                fa[r2] = r1;
                val[r2] = val[u] - val[v];
            } else if (abs(val[v] - val[u]) % 3 != 0)
                ++ans;
        } else {
            if (r1 != r2) {
                fa[r2] = r1;
                val[r2] = val[u] + 1 - val[v];
            } else if ((val[u] - val[v] + 1) % 3 != 0)
                ++ans;
        }
    }
    printf("%d\n", ans);

    return 0;
}