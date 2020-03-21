#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100;

/*
定义一个parent数组，并全部初始化为-1。
最终得到的parent数组，若为正数则为父节点序号，复数则为根节点且绝对值为组团元素个数。
*/

int parent[maxn];

//一般并查集
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

//带权并查集
int N, M, x, y, w, ans;
int fa[maxn], val[maxn];

inline void init() {
    ans = 0;
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        val[i] = 0;
    }
}

int find_with_value(int x) {
    if (x == fa[x]) return x;
    int root = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = root;
}

//极简并查集
int simple_find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    memset(parent, -1, sizeof(parent));
    //带权并查集
    init();
    for (int i = 1; i <= M; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        int r1 = find(x), r2 = find(y);
        if (r1 != r2) {
            fa[r2] = r1;
            val[r2] = val[x] + w - val[y];  //带权并查集转移方程，视题目而定
        }
    }

    return 0;
}