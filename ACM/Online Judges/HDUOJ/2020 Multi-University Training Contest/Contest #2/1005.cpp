#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e4 + 5;
constexpr int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
    ll cost;
    int next;
} edge[maxn];

int t, n, m, tot, S, T;
ll a[maxn], b[maxn], c[maxn], dis[maxn];
set<int> all, connect[maxn];
map<int, int> id;
int head[maxn], pre[maxn];
bool vis[maxn];

inline ll f(int i, int j) { return a[i] * j * j + b[i] * j + c[i]; }

void extend(int x, set<int> &s) {
    ll tmp = -b[x] / (a[x] * 2);
    tmp = max(tmp, 1ll);
    tmp = min(tmp, 1ll * m);
    ll l = tmp, r = tmp + 1;
    for (int i = 1; i <= n; ++i) {
        if (l < 1)
            s.insert(r++);
        else if (r > m)
            s.insert(l--);
        else if (f(x, l) < f(x, r))
            s.insert(l--);
        else
            s.insert(r++);
    }
    for (int i : s) all.insert(i);
}

inline void init() {
    all.clear();
    id.clear();
    tot = 1;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; ++i) connect[i].clear();
}

inline void add_edge(int u, int v, int w, ll cost) {
    edge[++tot] = {u, v, w, cost, head[u]};
    head[u] = tot;
    edge[++tot] = {v, u, 0, -cost, head[v]};
    head[v] = tot;
}

bool spfa() {
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    dis[S] = 0;
    queue<int> q;
    q.push(S);
    vis[S] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (edge[i].w) {
                int v = edge[i].v;
                if (dis[u] + edge[i].cost < dis[v]) {
                    dis[v] = dis[u] + edge[i].cost;
                    pre[v] = i;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    return pre[T] != -1;
}

void min_cost_max_flow() {
    ll ret = 0;
    for (int i = 1; i <= n; ++i) {
        spfa();
        int flow = inf;
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v)
            flow = min(edge[pre[i]].w, flow);
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v) {
            edge[pre[i]].w -= flow;
            edge[pre[i] ^ 1].w += flow;
            ret += edge[pre[i]].cost * flow;
        }
        cout << ret << " \n"[i == n];
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            extend(i, connect[i]);
        }
        int cnt = 0;
        for (int i : all) id[i] = ++cnt;
        S = 0, T = n + cnt + 1;
        for (int i = 1; i <= n; ++i) add_edge(S, i, 1, 0);
        for (int i = 1; i <= cnt; ++i) add_edge(n + i, T, 1, 0);
        for (int i = 1; i <= n; ++i)
            for (int j : connect[i]) add_edge(i, n + id[j], 1, f(i, j));
        min_cost_max_flow();
    }

    return 0;
}