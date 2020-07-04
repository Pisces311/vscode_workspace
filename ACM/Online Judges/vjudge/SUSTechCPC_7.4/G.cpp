#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr int maxm = 2e5 + 5;

struct Edge {
    int u, v, w, next;
} edge[maxm];

struct node {
    int id;
    ll dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int T, n, m, tot;
int head[maxn];
ll dis[maxn][2];

inline void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
    edge[++tot] = {v, u, w, head[v]};
    head[v] = tot;
}

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> pq;
    pq.push({1, 0});
    dis[1][0] = 0;
    while (!pq.empty()) {
        node u = pq.top();
        pq.pop();
        for (int i = head[u.id]; i != -1; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            ll d = u.dis + w;
            if (dis[v][0] > d) {
                swap(dis[v][0], d);
                pq.push({v, dis[v][0]});
            }
            if (dis[v][1] > d) {
                dis[v][1] = d;
                pq.push({v, dis[v][1]});
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
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        init();
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        dijkstra();
        cout << dis[n][1] << '\n';
    }

    return 0;
}