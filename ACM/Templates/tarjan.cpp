#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const int maxm = 1e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxm];

int order = 0, scc = 0;
int head[maxn];
int dfn[maxn], low[maxn], id[maxn], num[maxn], in[maxn];
stack<int> stk;

/*
有向图tarjan：
order记录访问顺序，scc记录强连通分量个数.
dfn数组记录访问时间点（时间戳），low数组记录当前这个点能联通到的最小访问时间的点（dfn==low即强连通）
belong数组记录当前这个点属于哪个强连通分量（缩点），num记录每个强连通分量有多少个点，in记录是否在栈中

无向图tarjan：
tarjan函数加上一个int fa参数，如果v==fa则continue.

无向图带重边：
开一个对于每条边来说的vis数组，如果满足条件(vis[i]||vis[i^1])则是同一条边，否则是重边可以回去。
*/

void tarjan(int u) {
    low[u] = dfn[u] = ++order;
    stk.push(u);
    in[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        int t;
        do {
            t = stk.top();
            stk.pop();
            in[t] = false;
            id[t] = scc;
            num[scc]++;
        } while (t != u);
    }
}

int main() { return 0; }