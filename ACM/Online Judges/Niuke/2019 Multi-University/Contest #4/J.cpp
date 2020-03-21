#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
const int maxm = 500500;

struct Edge {
    int u, v, w, next;
} edge[maxm * 42];

struct node {
    int u, dis;
    bool operator<(const node x) const { return dis > x.dis; }
};

int n, m, S, T, k;
int head[maxn * 42], tot;
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
const int maxm = 500500;

int nextt[maxm * 42], w[maxm * 42], to[maxm * 42], head[maxn * 42], cnt = 0;

void add(int u, int v, int cost) {
    cnt++;
    nextt[cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    w[cnt] = cost;
}

struct node {
    int u, dis;
    bool operator<(const node x) const { return dis > x.dis; }
};

priority_queue<node> q;
int dist[maxn * 21];

void dij(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push((node){s, 0});
    while (!q.empty()) {
        node fr = q.top();
        q.pop();
        int u = fr.u, dis = fr.dis;
        if (dis != dist[u]) continue;
        for (int v = head[u]; v; v = nextt[v])
            if (dist[to[v]] > dist[u] + w[v]) {
                dist[to[v]] = dist[u] + w[v];
                q.push((node){to[v], dist[to[v]]});
            }
    }
}

int n, m, S, T, k;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d %d %d", &n, &m, &S, &T, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        add(u, v, cost);
        add(v, u, cost);
        for (int j = 1; j <= k; j++) {
            add(n * j + u, n * j + v, cost);
            add(n * j + v, n * j + u, cost);
            add(n * (j - 1) + u, n * j + v, 0);
            add(n * (j - 1) + v, n * j + u, 0);
        }
    }
    dij(S);
    int ans = dist[T];
    for (int i = 1; i <= k; i++) {
        ans = min(ans, dist[i * n + T]);
    }
    printf("%d\n", ans);

    return 0;
}
inline void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

priority_queue<node> q;
int dist[maxn * 21];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (t.dis != dist[t.u]) continue;
        for (int i = head[t.u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[v] > dist[t.u] + t.dis) {
                dist[v] = dist[t.u] + t.dis;
                q.push({v, dist[v]});
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d %d %d", &n, &m, &S, &T, &k);
    init();
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
        for (int j = 1; j <= k; ++j) {
            add_edge(n * j + u, n * j + v, w);
            add_edge(n * j + v, n * j + u, w);
            add_edge(n * (j - 1) + u, n * j + v, 0);
            add_edge(n * (j - 1) + v, n * j + u, 0);
        }
    }
    dijkstra(S);
    int ans = dist[T];
    for (int i = 1; i <= k; ++i) ans = min(ans, dist[i * n + T]);
    printf("%d\n", ans);

    return 0;
}