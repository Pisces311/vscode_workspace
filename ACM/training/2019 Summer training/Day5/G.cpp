#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

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

int N, M, A, B, tot, rtot, S, T, K;
int head[maxn], rhead[maxn], h[maxn];
bool vis[maxn];

inline void init() {
    tot = rtot = -1;
    mem(head, -1);
    mem(rhead, -1);
    mem(vis, false);
    mem(h, inf);
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

inline void add_redge(int u, int v, int w) {
    redge[++rtot] = {u, v, w, rhead[u]};
    rhead[u] = rtot;
}

void dijkstra(int S) {
    priority_queue<node> pq;
    pq.push({S, 0});
    h[S] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        for (int i = rhead[t.v]; i != -1; i = redge[i].next)
            if (!vis[redge[i].v]) {
                int v = redge[i].v;
                if (h[v] > h[t.v] + redge[i].w) {
                    h[v] = h[t.v] + redge[i].w;
                    pq.push({v, h[v]});
                }
            }
    }
}

int A_star(int S, int T, int K) {
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
        link(i, t.v) {
            int v = edge[i].v, w = edge[i].w;
            q.push({v, t.w + w, t.w + w + h[v]});
        }
    }
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &M)) {
        init();
        up(i, 1, M) {
            scanf("%d %d %d", &A, &B, &T);
            add_edge(A, B, T);
            add_redge(B, A, T);
        }
        scanf("%d %d %d", &S, &T, &K);
        dijkstra(T);
        printf("%d\n", A_star(S, T, K));
    }

    return 0;
}