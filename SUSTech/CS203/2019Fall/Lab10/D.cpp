#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct Edge {
    int u, v, w;
} edge[maxn];

int n, m;
int c[maxn], fa[maxn];

int id(int x, int y) { return (x - 1) * m + y; }

int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> c[id(i, j)];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fa[id(i, j)] = id(i, j);
            if (i != n)
                edge[++cnt] = {id(i, j), id(i + 1, j),
                               c[id(i, j)] * c[id(i + 1, j)]};
            if (j != m)
                edge[++cnt] = {id(i, j), id(i, j + 1),
                               c[id(i, j)] * c[id(i, j + 1)]};
        }
    }
    sort(edge + 1, edge + cnt + 1,
         [](const Edge& a, const Edge& b) { return a.w > b.w; });
    ll ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        int x = find(edge[i].u), y = find(edge[i].v);
        if (x != y) {
            ans += 1ll * edge[i].w;
            fa[x] = y;
        }
    }
    cout << ans << '\n';

    return 0;
}