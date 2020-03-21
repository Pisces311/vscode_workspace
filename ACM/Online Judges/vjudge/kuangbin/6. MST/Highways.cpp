#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 755;

struct node {
    int x, y;
    double operator-(const node& a) {
        return sqrt(1.0 * pow(x - a.x, 2) + pow(y - a.y, 2));
    }
} p[maxn];

struct EDGE {
    int u, v;
    double w;
    bool operator<(const EDGE& a) const { return w < a.w; }
} edge[maxn * maxn];

int N, M, u, v, top = 0;
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

    cin >> N;
    up(i, 1, N) cin >> p[i].x >> p[i].y;
    cin >> M;
    mem(parent, -1);
    up(i, 1, M) {
        cin >> u >> v;
        int x = find(u), y = find(v);
        if (x != y) Union(x, y);
    }
    up(i, 1, N) up(j, i + 1, N) {
        int x = find(i), y = find(j);
        if (x != y) edge[++top] = {i, j, p[i] - p[j]};
    }
    sort(edge + 1, edge + top + 1);
    up(i, 1, top) {
        int x = find(edge[i].u), y = find(edge[i].v);
        if (x != y) {
            cout << edge[i].u << ' ' << edge[i].v << endl;
            Union(x, y);
        }
    }

    return 0;
}