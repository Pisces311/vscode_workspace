#include <string.h>

#include <iostream>
#include <numeric>
#include <queue>
using namespace std;

typedef long long ll;
const int maxn = 4e2 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int F, P;
int cow[maxn], slt[maxn];
ll dis[maxn][maxn];

int S = 1, T, tot;
int head[maxn];
int h[maxn], e[maxn], gap[maxn << 1];
bool inq[maxn];

struct cmp {
    inline bool operator()(int a, int b) const { return h[a] < h[b]; }
};

priority_queue<int, vector<int>, cmp> pq;

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
    memset(e, 0, sizeof(e));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
    edge[++tot] = {v, u, 0, head[v]};
    head[v] = tot;
}

bool bfs() {
    memset(h, inf, sizeof(h));
    h[T] = 0;
    queue<int> q;
    q.push(T);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i ^ 1].w && h[v] > h[u] + 1) {
                h[v] = h[u] + 1;
                q.push(v);
            }
        }
    }
    return h[S] != inf;
}

void push(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (edge[i].w && h[v] + 1 == h[u]) {
            int d = min(e[u], edge[i].w);
            edge[i].w -= d;
            edge[i ^ 1].w += d;
            e[u] -= d;
            e[v] += d;
            if (v != S && v != T && !inq[v]) {
                pq.push(v);
                inq[v] = true;
            }
            if (!e[u]) break;
        }
    }
}

inline void relabel(int u) {
    h[u] = inf;
    for (int i = head[u]; i != -1; i = edge[i].next)
        if (edge[i].w && h[edge[i].v] + 1 < h[u]) h[u] = h[edge[i].v] + 1;
}

// n: 总点数
int hlpp(int n) {
    if (!bfs()) return 0;
    h[S] = n;
    memset(gap, 0, sizeof(gap));
    for (int i = 1; i <= n; ++i)
        if (h[i] < inf) ++gap[h[i]];
    for (int i = head[S]; i != -1; i = edge[i].next) {
        int v = edge[i].v, w = edge[i].w;
        if (h[v] < inf && w) {
            edge[i].w -= w;
            edge[i ^ 1].w += w;
            e[S] -= w;
            e[v] += w;
            if (v != S && v != T && !inq[v]) {
                pq.push(v);
                inq[v] = true;
            }
        }
    }
    while (pq.size()) {
        int u = pq.top();
        pq.pop();
        inq[u] = false;
        push(u);
        if (e[u]) {
            if (!--gap[h[u]])  // gap优化
                for (int i = 1; i <= n; ++i)
                    if (i != S && i != T && h[i] > h[u] && h[i] < n + 1)
                        h[i] = n + 1;
            relabel(u);
            ++gap[h[u]];
            pq.push(u);
            inq[u] = true;
        }
    }
    return e[T];
}

void floyd() {
    for (int k = 1; k <= F; ++k)
        for (int i = 1; i <= F; ++i)
            for (int j = 1; j <= F; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

bool check(ll mid) {
    init();
    for (int i = 1; i <= F; ++i) {
        add_edge(S, i + 1, cow[i]);
        add_edge(i + 1 + F, T, slt[i]);
    }
    for (int i = 1; i <= F; ++i) {
        for (int j = 1; j <= F; ++j) {
            if (dis[i][j] <= mid) {
                add_edge(i + 1, j + 1 + F, inf);
            }
        }
    }
    return hlpp(1 + 2 * F + 1) == accumulate(cow + 1, cow + F + 1, 0);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> F >> P;
    for (int i = 1; i <= F; ++i) cin >> cow[i] >> slt[i];
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= F; ++i) dis[i][i] = 0;
    for (int i = 1; i <= P; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    floyd();
    S = 1, T = 1 + 2 * F + 1;
    ll l = 0, r = 1e14, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    cout << ans << '\n';

    return 0;
}