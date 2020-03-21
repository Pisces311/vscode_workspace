#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 5e5 + 5;

int n, m, k, x, y;
int parent[maxn];

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] >= 0; pos = parent[pos])
        ;
    while (pos != x) {
        int tmp = parent[x];
        parent[x] = pos;
        x = tmp;
    }
    return pos;
}

inline void Union(int u, int v) {
    int tmp = parent[u] + parent[v];
    if (u < v) {
        parent[u] = tmp;
        parent[v] = u;
    } else {
        parent[u] = v;
        parent[v] = tmp;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    mem(parent, -1);
    scanf("%d %d", &n, &m);
    up(i, 1, m) {
        scanf("%d", &k);
        if (k > 0) {
            scanf("%d", &x);
            --k;
        }
        while (k--) {
            scanf("%d", &y);
            int u = find(x), v = find(y);
            if (u != v) Union(u, v);
        }
    }
    up(i, 1, n) printf("%d ", -parent[find(i)]);
    printf("\n");

    return 0;
}