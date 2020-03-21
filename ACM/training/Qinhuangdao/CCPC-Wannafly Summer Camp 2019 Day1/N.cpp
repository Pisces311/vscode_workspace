#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int n, m;
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

    scanf("%d %d", &n, &m);
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= m; ++i) {
        int k, u, v;
        scanf("%d", &k);
        if (!k) continue;
        scanf("%d", &u);
        --k;
        while (k--) {
            scanf("%d", &v);
            int x = find(u), y = find(v);
            if (x != y) Union(x, y);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", -parent[find(i)]);
    }
    printf("\n");

    return 0;
}