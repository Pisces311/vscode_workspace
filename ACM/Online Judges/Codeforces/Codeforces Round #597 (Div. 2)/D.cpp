#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e3 + 5;

struct city {
    int x, y, cost, k;
} a[maxn];

struct node {
    int id, from;
    bool build;
    ll cost;
    bool operator<(const node& rhs) const { return cost > rhs.cost; }
};

int n;
ll ans = 0;
vector<int> ele;
vector<pii> edge;
bool vis[maxn];

void prim() {
    int cnt = n;
    priority_queue<node> pq;
    for (int i = 1; i <= n; ++i) pq.push({i, 0, true, a[i].cost});
    while (cnt--) {
        node u = pq.top();
        pq.pop();
        if (vis[u.id]) {
            ++cnt;
            continue;
        }
        vis[u.id] = true;
        if (u.build)
            ele.push_back(u.id);
        else
            edge.push_back(make_pair(u.id, u.from));
        ans += u.cost;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) {
                ll cost = 1ll *
                          (abs(a[u.id].x - a[i].x) + abs(a[u.id].y - a[i].y)) *
                          (a[u.id].k + a[i].k);
                pq.push({i, u.id, false, cost});
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

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; ++i) cin >> a[i].cost;
    for (int i = 1; i <= n; ++i) cin >> a[i].k;
    prim();
    cout << ans << '\n';
    cout << ele.size() << '\n';
    for (int i : ele) cout << i << ' ';
    cout << '\n';
    cout << edge.size() << '\n';
    for (pii e : edge) cout << e.first << ' ' << e.second << '\n';

    return 0;
}