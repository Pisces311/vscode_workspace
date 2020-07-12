#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3;
constexpr int maxm = 1e4;
constexpr int inf = 0x3f3f3f3f;

struct edge {
    int v, w, cost, next;
} edge[maxm];

int n, m, q;
int S, T, cnt, tot;
ll path[maxn];
int head[maxn], dis[maxn], pre[maxn];
bool vis[maxn];

void init() {
    cnt = 0;
    tot = -1;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w, int cost) {
    edge[++tot] = {v, w, cost, head[u]};
    head[u] = tot;
    edge[++tot] = {u, 0, -cost, head[v]};
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

void solve() {
    cnt = 0;
    while (spfa()) {
        ll ret = 0;
        int flow = inf;
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v)
            flow = min(edge[pre[i]].w, flow);
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v) {
            edge[pre[i]].w -= flow;
            edge[pre[i] ^ 1].w += flow;
            ret += 1ll * edge[pre[i]].cost * flow;
        }
        path[++cnt] = ret;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        init();
        S = 1, T = n;
        for (int i = 1; i <= m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            add_edge(a, b, 1, c);
        }
        solve();
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (!u) {
                cout << "NaN\n";
                continue;
            }
            int time = v / u, rest = v - time * u;
            if (time + (rest != 0) > cnt) {
                cout << "NaN\n";
                continue;
            }
            ll son = accumulate(path + 1, path + time + 1, 0ll) * u;
            ll mon = v;
            if (rest) son += path[time + 1] * rest;
            ll GCD = __gcd(son, mon);
            cout << son / GCD << '/' << mon / GCD << '\n';
        }
    }

    return 0;
}