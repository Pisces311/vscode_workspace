#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int maxn = 5e1 + 5;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int ans;
bool vis[maxn];
vector<node> g[maxn];
priority_queue<node> pq;

// 1为起点（prim可以从任意点开始）
void prim() {
    pq.push({1, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        ans += t.w;
        for (int i = 0; i < g[t.v].size(); ++i)
            if (!vis[g[t.v][i].v]) {
                int v = g[t.v][i].v;
                pq.push({v, g[t.v][i].w});
            }
    }
}

int n;
int w[maxn][maxn];
int lowc[maxn];

// prim朴素版本，处理邻接矩阵（完全图）比堆优化更快。
void prim() {
    vis[0] = true;
    for (int i = 1; i <= n - 1; ++i) lowc[i] = w[0][i];
    for (int i = 1; i <= n - 1; ++i) {
        int minc = INT_MAX;
        int p = -1;
        for (int j = 0; j <= n - 1; ++j) {
            if (!vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        }
        ans += minc;
        vis[p] = true;
        for (int j = 0; j <= n - 1; ++j)
            if (!vis[j] && lowc[j] > w[p][j]) lowc[j] = w[p][j];
    }
}

int main() { return 0; }