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

const int maxn = 1e6 + 5;

int T, n, m;
int parent[maxn], result[maxn], top;
vector<int> g[maxn];
bool vis[maxn];
priority_queue<int, vector<int>, greater<int> > pq;

inline void init() {
    mem(parent, -1);
    up(i, 1, n) g[i].clear();
    mem(vis, false);
    top = 0;
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
#endif

    scan(T);
    while (T--) {
        scanf("%d %d", &n, &m);
        init();
        int a, b;
        up(i, 1, m) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
            int x = find(a), y = find(b);
            if (x != y) Union(x, y);
        }
        up(i, 1, n) if (parent[i] < 0) pq.push(i);
        print(pq.size());
        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            if (vis[t]) continue;
            vis[t] = true;
            result[++top] = t;
            up(i, 0, (int)g[t].size() - 1) if (!vis[g[t][i]]) pq.push(g[t][i]);
        }
        up(i, 1, top) {
            printf("%d", result[i]);
            if (i != top) printf(" ");
        }
        printf("\n");
    }

    return 0;
}