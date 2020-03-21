#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;
const int maxm = 1e3 + 5;

struct EDGE {
    int u, v, w;
    bool operator<(const EDGE& a) const { return w < a.w; }
} edge[maxm];

struct node {
    int v, w;
};

int n, m, ans, sub_ans;
int parent[maxn], dis[maxn][maxn];
bool vis[maxm];
vector<node> g[maxn];

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

//通过dfs将最小瓶颈路上最大权值边记录在dis数组中
void dfs_mini(int s, int x, int pre, int maxs) {
    dis[s][x] = maxs;
    for (node i : g[x]) {
        int v = i.v;
        if (v != pre) dfs_mini(s, v, x, max(i.w, maxs));
    }
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

//先求出MST，然后枚举每条未使用过的边，将该边添加到MST中形成环，然后删去环中最大权值边（不能是该条边）。最后结果取所有情况最小值即可。
int main() {
    for (int i = 1; i <= n; ++i) dfs_mini(i, i, 0, 0);
    for (int i = 1; i <= m; ++i)
        if (!vis[i])
            sub_ans = min(sub_ans, ans - dis[edge[i].u][edge[i].v] + edge[i].w);
    cout << ans << '\n';
    return 0;
}