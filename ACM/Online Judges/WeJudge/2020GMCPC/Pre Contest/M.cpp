#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int x, y;
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
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    memset(parent, -1, sizeof(parent));
    while (cin >> x && x != -1) {
        cin >> y;
        int u = find(x), v = find(y);
        if (u == v)
            ++ans;
        else
            Union(u, v);
    }
    cout << ans << '\n';

    return 0;
}