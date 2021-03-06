#include <string.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100010;

struct node {
    int v;
    ll c;
    int cnt;
    bool operator<(const node& r) const { return c > r.c; }
};

struct edge {
    int to, cost;
};

int n, m, p, k, S, T;
ll dis[maxn][12];
vector<edge> g[maxn];

ll dijkstra(int s, int t, int k) {
    memset(dis, inf, sizeof(dis));
    priority_queue<node> q;
    dis[s][0] = 0;
    q.push({s, dis[s][0], 0});
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int u = tmp.v, cnt = tmp.cnt;
        if (u == t) return tmp.c;
        for (edge i : g[u]) {
            int v = i.to, cost = i.cost;
            if (cost && dis[u][cnt] + cost < dis[v][cnt]) {
                dis[v][cnt] = dis[u][cnt] + cost;
                q.push({v, dis[v][cnt], cnt});
            }
            if (!cost && cnt + 1 <= k && dis[u][cnt] < dis[v][cnt + 1]) {
                dis[v][cnt + 1] = dis[u][cnt];
                q.push({v, dis[v][cnt + 1], cnt + 1});
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

    cin >> n >> m >> p >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, 0});
    }
    cin >> S >> T;
    cout << dijkstra(S, T, k) << '\n';

    return 0;
}