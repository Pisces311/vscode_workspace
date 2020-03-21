#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int n, m, edge = 0;
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
    if (u > v) {
        parent[u] = tmp;
        parent[v] = u;
    } else {
        parent[u] = v;
        parent[v] = tmp;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        int x = find(u), y = find(v);
        if (x != y) Union(x, y);
    }
    for (int i = 1; i <= n; ++i) {
        int fa = find(i);
        for (int j = i + 1; j <= fa; ++j) {
            int faj = find(j);
            if (faj != fa) {
                ++edge;
                Union(fa, faj);
            }
            fa = max(fa, faj);
        }
        i = fa;
    }
    cout << edge << '\n';

    return 0;
}