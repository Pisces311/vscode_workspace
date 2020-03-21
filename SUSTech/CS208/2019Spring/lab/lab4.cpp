#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e3 + 5;

struct EDGE{
    int u, v, w;
    friend bool operator<(const EDGE& a, const EDGE& b) { return a.w < b.w; }
} edge[maxn*maxn];

int N, w, top = 0, sum = 0;
int parent[maxn];

inline int find(int x) {
    int pos;
    for (pos = x; parent[pos] > 0; pos = parent[pos]);
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

    scan(N);
    up(i, 1, N){
        up(j, i, N) { 
            scan(w);
            edge[++top] = {i, j + 1, w};
        }
    }
    sort(edge + 1, edge + top + 1);
    memset(parent, -1, sizeof(parent));
    up(i, 1, top){
        int u = find(edge[i].u), v = find(edge[i].v);
        if(u != v){
            sum += edge[i].w;
            Union(u, v);
        }
    }
    print(sum);

    return 0;
}