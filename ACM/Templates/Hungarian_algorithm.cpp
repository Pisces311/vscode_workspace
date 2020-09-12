#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

//二分图最小顶点覆盖=最大匹配
//二分图最大独立集=总点数-二分图最小顶点覆盖
//二分图最大团=补图的最大独立集

bool vis[maxn];          //记录是否已经连边
vector<int> x, y;        //存储左图和右图的节点
int cx[maxn], cy[maxn];  //存储左图和右图的连边对象
int edge[maxn][maxn];    // 邻接矩阵

int dfs(int u) {
    // vis[u] = true
    for (int v : y) {
        if (edge[u][v] && !vis[v]) {
            vis[v] = true;
            if (cy[v] == -1 || dfs(cy[v])) {  //若未连边或递归查找可以改连边对象
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int sum = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i : x) {
        if (cx[i] == -1) {
            memset(vis, false, sizeof(vis));
            sum += dfs(i);
        }
    }
    return sum;  //返回值为最大匹配的个数
}