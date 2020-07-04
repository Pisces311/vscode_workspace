#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int maxn = 1e3 + 5;
constexpr int inf = 0x3f3f3f3f;

struct node {
    int v, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int dis[maxn];
vector<node> g[maxn];

/*
不可用于有负权边的图。
*/

void dijkstra(int s) {
    memset(dis, inf, sizeof(dis));
    priority_queue<node> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        for (int i = 0; i < g[t.v].size(); ++i) {
            int v = g[t.v][i].v;
            if (dis[v] > dis[t.v] + g[t.v][i].dis) {
                dis[v] = dis[t.v] + g[t.v][i].dis;
                pq.push({v, dis[v]});
            }
        }
    }
}