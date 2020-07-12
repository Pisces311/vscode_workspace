#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1e5 + 5;

ull n;
int m, u, v;
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
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(parent, -1, sizeof(parent));
    cin >> n >> m;
    ull ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4, s = n;
    while (m--) {
        cout << ans << '\n';
        cin >> u >> v;
        int x = find(u), y = find(v);
        if (x != y) {
            ull a = -parent[x], b = -parent[y];
            ans -= a * b * ((n - a - b) * (n - a - b) - s + a * a + b * b) / 2;
            s += 2 * a * b;
            Union(x, y);
        }
    }
    cout << ans << '\n';

    return 0;
}