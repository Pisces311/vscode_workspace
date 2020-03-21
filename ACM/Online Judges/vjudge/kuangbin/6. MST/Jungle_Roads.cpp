#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 101;

struct EDGE {
    int u, v, w;
    bool operator<(const EDGE& a) const { return w < a.w; }
} g[maxn];

int n, num, w, top, ans;
char u, v;
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
    if (parent[u] > parent[v]) {
        parent[u] = v;
        parent[v] = tmp;
    } else {
        parent[v] = u;
        parent[u] = tmp;
    }
}

inline void init() {
    mem(parent, -1);
    top = 0;
    ans = 0;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> n && n) {
        init();
        up(i, 1, n - 1) {
            cin >> u >> num;
            up(j, 1, num) {
                cin >> v >> w;
                g[++top] = {u - 'A' + 1, v - 'A' + 1, w};
            }
        }
        sort(g + 1, g + top + 1);
        up(i, 1, top) {
            int x = find(g[i].u), y = find(g[i].v);
            if (x == y) continue;
            Union(x, y);
            ans += g[i].w;
        }
        cout << ans << endl;
    }

    return 0;
}