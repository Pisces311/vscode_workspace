#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

int n, order, edge;
int dfn[maxn], low[maxn];
vector<int> g[maxn];

/*
tarjan求割边。
dfn数组记录访问时间点（时间戳），low数组记录当前这个点能联通到的最小访问时间的点。
对于一条边(u, v)如果满足low[v]>dfn[u]则该边为割边。
*/

void tarjan(int u, int pre) {
    low[u] = dfn[u] = ++order;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == pre) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) ++edge;
        } else
            low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i, -1);
    return 0;
}