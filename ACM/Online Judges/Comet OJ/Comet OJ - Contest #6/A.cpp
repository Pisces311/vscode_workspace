#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 3e2 + 5;
const int inf = 0x3f3f3f3f;

int n, m, u, v;
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
    mem(parent, -1);
    up(i, 1, m) {
        scanf("%d %d", &u, &v);
        int x = find(u), y = find(v);
        if (x != y) Union(x, y);
    }
    int cnt = 0;
    up(i, 1, n) if (parent[i] < 0)++ cnt;
    printf(cnt & 1 ? "Star-dust\n" : "Illyasviel\n");

    return 0;
}