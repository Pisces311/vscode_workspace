#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e5 + 5;

struct node {
    int id, t;
} a[maxn];

int n, m;
int deg[maxn];
bool vis[maxn];
vector<int> g[maxn], order;

bool check() {
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j : g[i]) {
            if (a[j].t == cnt + 1) cnt += 1;
            if (cnt == a[i].t) return false;
        }
        if (cnt != a[i].t - 1) return false;
    }
    return true;
}

void solve() {
    queue<node> q;
    for (int i = 1; i <= n; ++i)
        if (a[i].t == 1) q.push(a[i]);
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        if (vis[u.id]) continue;
        vis[u.id] = true;
        order.push_back(u.id);
        for (int v : g[u.id]) {
            if (a[v].t == u.t + 1) {
                q.push(a[v]);
            }
        }
    }
}

bool cmp(int x, int y) { return a[x].t < a[y].t; }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        a[i].id = i;
        cin >> a[i].t;
    }
    for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end(), cmp);
    if (check()) {
        solve();
        for (int i : order) cout << i << ' ';
        cout << '\n';
    } else
        cout << "-1\n";

    return 0;
}