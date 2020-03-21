#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& a) { return w < a.w; }
} edge[maxn * maxn];

int N, u, v, w, top, ans;
int parent[maxn];

inline void init() {
    top = ans = 0;
    mem(parent, -1);
}

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

    while (scanf("%d", &N) && N) {
        init();
        up(i, 1, N * (N - 1) / 2) {
            scanf("%d %d %d", &u, &v, &w);
            edge[++top] = {u, v, w};
        }
        sort(edge + 1, edge + top + 1);
        up(i, 1, top) {
            int x = find(edge[i].u), y = find(edge[i].v);
            if (x != y) {
                Union(x, y);
                ans += edge[i].w;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}