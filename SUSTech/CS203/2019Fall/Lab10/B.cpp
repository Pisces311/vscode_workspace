#include <string.h>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int n, m;
int dis[maxn];
bool vis[maxn];
vector<node> g[maxn];

void prim() {
    memset(dis, inf, sizeof(dis));
    priority_queue<node> pq;
    pq.push({1, 0});
    dis[1] = 0;
    ll ans = 0;
    while (pq.size()) {
        node u = pq.top();
        pq.pop();
        if (vis[u.v]) continue;
        vis[u.v] = true;
        ans += dis[u.v];
        for (node v : g[u.v]) {
            if (dis[v.v] > v.w) {
                dis[v.v] = v.w;
                pq.push({v.v, v.w});
            }
        }
    }
    cout << ans << '\n';
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
        g[v].push_back({u, w});
    }
    prim();

    return 0;
}