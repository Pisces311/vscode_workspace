#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

struct EDGE {
    int u, v, w;
    bool operator<(const EDGE& a) const { return w < a.w; }
} edge[maxn * maxn];

int N, ans;
int parent[maxn];

inline void init() {
    ans = 0;
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
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
    freopen("E:/source/Visual Studio Code/out.txt", "w", stdout);
#endif

    while (~scanf("%d", &N) && N) {
        int M = N * (N - 1) / 2;
        init();
        up(i, 1, M) scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge + 1, edge + M + 1);
        up(i, 1, M) {
            int x = find(edge[i].u), y = find(edge[i].v);
            if (x == y) continue;
            Union(x, y);
            ans += edge[i].w;
        }
        printf("%d\n", ans);
    }

    return 0;
}