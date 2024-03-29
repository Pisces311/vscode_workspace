#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e1 + 5;
const int maxm = 5e2 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm << 1];

int n, m, S, T, tot;
int head[maxn];
int h[maxn], e[maxn], gap[maxn << 1];
bool inq[maxn], inS[maxn];

struct cmp {
    inline bool operator()(int a, int b) const { return h[a] < h[b]; }
};

priority_queue<int, vector<int>, cmp> pq;

inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
    memset(e, 0, sizeof(e));
    memset(inS, false, sizeof(inS));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
    edge[++tot] = {v, u, w, head[v]};
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

int hlpp() {
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

void findS(int u) {
    inS[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (inS[v] || edge[i].w <= 0) continue;
        findS(v);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m, n + m) {
        init();
        S = 1, T = 2;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        int flow = hlpp();
        findS(S);
        for (int i = 0; i <= tot; ++i) {
            int u = edge[i].u, v = edge[i].v;
            if (inS[u] && !inS[v]) cout << u << ' ' << v << '\n';
        }
        cout << '\n';
    }

    return 0;
}