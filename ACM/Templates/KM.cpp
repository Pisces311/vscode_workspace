#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e2 + 5;
const int inf = 0x3f3f3f3f;

int wx[maxn], wy[maxn];       //每个点的顶标值
int cx[maxn], cy[maxn];       //存储左图和右图的连边对象
bool visx[maxn], visy[maxn];  //每个点是否加入增广路
int cntx, cnty;               //分别是X和Y的点数
int edge[maxn][maxn];         //领接矩阵
int slack[maxn];              //边权和顶标最小的差值

bool dfs(int u) {
    visx[u] = true;
    for (int v = 1; v <= cnty; ++v) {
        if (edge[u][v] && !visy[v]) {
            int t = wx[u] + wy[v] - edge[u][v];
            if (!t) {
                visy[v] = true;
                if (cy[v] == -1 || dfs(cy[v])) {
                    cx[u] = v;
                    cy[v] = u;
                    return true;
                }
            } else {
                slack[v] = min(slack[v], t);
                // slack[v]存的是Y部的点需要变成相等子图顶标值最小增加多少
            }
        }
    }
    return false;
}

int KM() {
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    memset(wx, 0, sizeof(wx));  // wx的顶标为该点连接的边的最大权值
    memset(wy, 0, sizeof(wy));
    for (int i = 1; i <= cntx; ++i) {
        for (int j = 1; j <= cnty; ++j) {
            wx[i] = max(wx[i], edge[i][j]);
        }
    }
    for (int i = 1; i <= cntx; ++i) {
        memset(slack, inf, sizeof(slack));
        while (1) {
            memset(visx, false, sizeof(visx));
            memset(visy, false, sizeof(visy));
            if (dfs(i)) break;
            int minz = inf;
            for (int j = 1; j <= cnty; ++j)
                if (!visy[j]) minz = min(minz, slack[j]);
            //还未匹配，将X部的顶标减去minz，Y部的顶标加上minz
            for (int j = 1; j <= cntx; ++j)
                if (visx[j]) wx[j] -= minz;
            //修改顶标后，要把所有不在交错树中的Y顶点的slack值都减去minz
            for (int j = 1; j <= cnty; ++j)
                if (visy[j])
                    wy[j] += minz;
                else
                    slack[j] -= minz;
        }
    }
    int ans = 0;
    for (int i = 1; i <= cntx; ++i)
        if (cx[i] != -1) ans += edge[i][cx[i]];
    return ans;
}