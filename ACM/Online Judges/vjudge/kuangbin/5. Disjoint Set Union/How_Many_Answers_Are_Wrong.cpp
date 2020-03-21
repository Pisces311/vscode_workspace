#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 2e5 + 5;

int N, M, u, v, w, ans;
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

    while (~scanf("%d %d", &N, &M)) {
        init();
        up(i, 1, M) {
            scanf("%d %d %d", &u, &v, &w);
            --u;
            int r1 = find(u), r2 = find(v);
            if (r1 != r2) {
                fa[r2] = r1;
                val[r2] = val[u] + w - val[v];
            } else if (w != val[v] - val[u])
                ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}