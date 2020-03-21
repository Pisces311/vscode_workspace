#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;

int u, v;
int parent[maxn];
vector<pair<int, int> > g;

inline void init() {
    mem(parent, -1);
    g.clear();
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

    while (true) {
        init();
        while (~scanf("%d %d", &u, &v)) {
            if (u == 0 && v == 0) break;
            if (u == -1 && v == -1) return 0;
            g.push_back({u, v});
        }
        bool ok = true;
        for (auto i : g) {
            int x = find(i.first), y = find(i.second);
            if (x != y)
                Union(x, y);
            else
                ok = false;
        }
        int cnt = 0;
        up(i, 1, 1e5) {
            if (parent[i] < -1) ++cnt;
            if (cnt >= 2) {
                ok = false;
                break;
            }
        }
        if (ok)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}