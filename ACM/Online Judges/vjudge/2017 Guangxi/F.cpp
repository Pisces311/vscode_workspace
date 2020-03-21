#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

struct node {
    int x, y;
} tow[maxn];

struct EDGE {
    int u, v, w;
    bool operator<(const EDGE& a) const { return w > a.w; }
} edge[maxm];

int n, m, u, v, w, cnt;
int parent[maxn];
ll ans;

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] > 0; pos = parent[pos])
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

    while (~scanf("%d %d", &n, &m)) {
        up(i, 1, n) scanf("%d %d", &tow[i].x, &tow[i].y);
        up(i, 1, m) {
            scanf("%d %d %d", &u, &v, &w);
            edge[i] = {u, v, w};
        }
        sort(edge + 1, edge + m + 1);
        mem(parent, -1);
        ans = 0;
        cnt = 0;
        up(i, 1, m) {
            int x = find(edge[i].u), y = find(edge[i].v);
            if (x != y) {
                Union(x, y);
            } else {
                ++cnt;
                ans += edge[i].w;
            }
        }
        printf("%d %lld\n", cnt, ans);
    }

    return 0;
}