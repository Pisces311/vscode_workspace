#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct edge {
    int u, v, w, next;
} edge[maxm], redge[maxm];

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

struct node2 {
    int v, w, f;
    bool operator<(const node2& a) const {
        return f == a.f ? w > a.w : f > a.f;
    };
};

int tot, rtot;
int head[maxn], rhead[maxn], h[maxn];

inline void init() {
    tot = rtot = -1;
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    memset(h, inf, sizeof(h));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
    redge[++rtot] = {v, u, w, rhead[v]};
    rhead[v] = rtot;
}

void dijkstra(int S) {
    priority_queue<node> pq;
    pq.push({S, 0});
    h[S] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        for (int i = rhead[t.v]; i != -1; i = redge[i].next) {
            int v = redge[i].v;
            if (h[v] > h[t.v] + redge[i].w) {
                h[v] = h[t.v] + redge[i].w;
                pq.push({v, h[v]});
            }
        }
    }
}

int A_star(int S, int T, int K) {
    dijkstra(T);
    if (S == T) ++K;
    if (h[S] == inf) return -1;
    priority_queue<node2> q;
    q.push({S, 0, h[S]});
    int cnt = 0;
    while (!q.empty()) {
        node2 t = q.top();
        q.pop();
        if (t.v == T) ++cnt;
        if (cnt == K) return t.w;
        for (int i = head[t.v]; i != -1; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            q.push({v, t.w + w, t.w + w + h[v]});
        }
    }
    return -1;
}