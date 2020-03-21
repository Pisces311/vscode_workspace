#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int m, n, k, val, cnt = 0;
int parent[maxn];
vector<int> g[maxn];

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

    scanf("%d %d", &m, &n);
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &val);
            g[val].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int x = find(g[i][0]), y = find(g[i][1]);
        if (x != y) {
            ++cnt;
            Union(x, y);
        }
    }
    printf("%d\n", cnt);

    return 0;
}