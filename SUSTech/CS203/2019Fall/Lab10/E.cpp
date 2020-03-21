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
bool vis[maxn][12];
vector<edge> g[maxn];

inline void init() {
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
}

ll dijkstra(int s, int t, int k) {
    init();
    priority_queue<node> q;
    dis[s][0] = 0;
    q.push({s, dis[s][0], 0});
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        int u = tmp.v, cnt = tmp.cnt;
        if (u == t) return tmp.c;
        if (vis[u][cnt]) continue;
        vis[u][cnt] = true;
        for (edge i : g[u]) {
            int v = i.to, cost = i.cost;
            if (cost && !vis[v][cnt] && dis[u][cnt] + cost < dis[v][cnt]) {
                dis[v][cnt] = dis[u][cnt] + cost;
                q.push({v, dis[v][cnt], cnt});
            }
            if (!cost && cnt + 1 <= k && !vis[v][cnt + 1] &&
                dis[u][cnt] < dis[v][cnt + 1]) {
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
    ll ans = inf;
    for (int i = 0; i <= k; ++i) ans = min(ans, dijkstra(S, T, i));
    cout << ans << '\n';

    return 0;
}