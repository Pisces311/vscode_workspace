#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 8e2 + 5;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w, next;
} edge[maxm << 1];

int N, F, D;
int food[205], drink[205];
char ac_food[205][205], ac_drink[205][205];
int n, S, T, tot;
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

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> F >> D) {
        init();
        for (int i = 1; i <= F; ++i) cin >> food[i];
        for (int i = 1; i <= D; ++i) cin >> drink[i];
        for (int i = 1; i <= N; ++i) cin >> (ac_food[i] + 1);
        for (int i = 1; i <= N; ++i) cin >> (ac_drink[i] + 1);
        n = 2 + F + 2 * N + D;
        S = 1, T = 2 * N + F + D + 2;
        for (int i = 1; i <= F; ++i) add_edge(S, i + 1, food[i]);
        for (int i = 1; i <= D; ++i) add_edge(2 * N + F + i + 1, T, drink[i]);
        for (int i = 1; i <= N; ++i) {
            add_edge(F + i + 1, F + N + i + 1, 1);
            for (int j = 1; j <= F; ++j)
                if (ac_food[i][j] == 'Y') add_edge(j + 1, F + i + 1, inf);
            for (int j = 1; j <= D; ++j)
                if (ac_drink[i][j] == 'Y')
                    add_edge(F + N + i + 1, 2 * N + F + j + 1, inf);
        }
        cout << hlpp() << '\n';
    }

    return 0;
}