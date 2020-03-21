#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int v, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int n, m;
int dis[maxn];
vector<node> g[maxn];

void dijkstra(int s) {
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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    memset(dis, inf, sizeof(dis));
    dijkstra(1);
    if (dis[n] != inf)
        cout << dis[n] << '\n';
    else
        cout << "-1\n";

    return 0;
}