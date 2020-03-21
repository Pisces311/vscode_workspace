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
    int id, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int n, m, S, T;
int dis[maxn];
vector<node> g[maxn];

void dijkstra(int S) {
    memset(dis, inf, sizeof(dis));
    priority_queue<node> pq;
    pq.push({S, 0});
    dis[S] = 0;
    while (pq.size()) {
        node u = pq.top();
        pq.pop();
        for (node v : g[u.id]) {
            if (dis[v.id] > dis[u.id] + v.w) {
                dis[v.id] = dis[u.id] + v.w;
                pq.push({v.id, dis[v.id]});
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
        g[v].push_back({u, w});
    }
    cin >> S >> T;
    dijkstra(S);
    cout << (dis[T] == inf ? -1 : dis[T]) << '\n';

    return 0;
}