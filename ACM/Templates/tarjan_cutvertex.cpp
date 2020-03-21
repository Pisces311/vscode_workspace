#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

int N, order;
bool cut[maxn];
int dfn[maxn], low[maxn];
vector<int> g[maxn];

/*
tarjan求割点。
dfn数组记录访问时间点（时间戳），low数组记录当前这个点能联通到的最小访问时间的点。
对于根节点，若其有两个子树（即子树无相连边，dfs两次）则为割点。
对于非根节点，一条边(u, v)如果满足low[v]>=dfn[u]则u为割点。
*/

void tarjan(int u, int pre) {
    low[u] = dfn[u] = ++order;
    int son = 0;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!dfn[v]) {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (pre != -1 && low[v] >= dfn[u]) cut[u] = true;
        } else
            low[u] = min(low[u], dfn[v]);
    }
    if (pre == -1 && son > 1) cut[u] = true;
}

int main() {
    for (int i = 1; i <= N; ++i)
        if (!dfn[i]) tarjan(i, -1);
    return 0;
}