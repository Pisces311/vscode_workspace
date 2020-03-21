#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

struct EDGE {
    int u, v, w;
    bool operator<(const EDGE& a) const { return w < a.w; }
} edge[maxn * maxn];

int N, Q, u, v, w, ans = 0;
int parent[maxn], top = 0;

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
    if (parent[u] > parent[v]) {
        parent[u] = v;
        parent[v] = tmp;
    } else {
        parent[v] = u;
        parent[u] = tmp;
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> N;
    up(i, 1, N) up(j, 1, N) {
        cin >> w;
        if (i != j) edge[++top] = {i, j, w};
    }
    sort(edge + 1, edge + N * N - N + 1);
    mem(parent, -1);
    cin >> Q;
    while (Q--) {
        cin >> u >> v;
        int x = find(u), y = find(v);
        if (x != y) Union(x, y);
    }
    up(i, 1, N * N - N) {
        int x = find(edge[i].u), y = find(edge[i].v);
        if (x == y) continue;
        Union(x, y);
        ans += edge[i].w;
    }
    cout << ans << endl;

    return 0;
}