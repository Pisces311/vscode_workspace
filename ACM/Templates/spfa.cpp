#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 5;

struct node {
    int v, t;
};

vector<node> g[maxn];
bool vis[maxn];
int dis[maxn];

/*
spfa用于处理有负权边的最短路问题或判断是否有负权环。
一般最短路图老老实实用dijkstra.
*/

bool spfa() {
    queue<int> q;
    dis[1] = 0;  //从1号节点开始跑spfa
    q.push(1);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        vis[f] = false;  //出队则取消标记
        for (int i = 0; i < g[f].size(); ++i) {
            int v = g[f][i].v;
            if (dis[v] > dis[f] + g[f][i].t) {
                dis[v] = dis[f] + g[f][i].t;
                if (dis[1] < 0)
                    return true;  //有负环的判断条件，一般来说一个节点最多进队n
                                  //- 1次，如果超过这个次数则有负权环
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int main() { return 0; }