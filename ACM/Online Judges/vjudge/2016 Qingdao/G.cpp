#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;
const int maxm = 4e4 + 5;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

struct Edge {
    int v, vol, next;
    double c;
} edge[maxm];

int t, n, m, u, v, cap, S, T;
int a[maxn], b[maxn], c[maxn];
int pre[maxn], path[maxn], head[maxn], tot;
bool vis[maxn];
double p;
double dis[maxn];

void add_edge(int u, int v, int vol, double c) {
    edge[++tot] = {v, vol, head[u], c};
    head[u] = tot;
    edge[++tot] = {u, 0, head[v], -c};
    head[v] = tot;
}

bool spfa(int s, int t) {
    for (int i = 0; i < maxn; ++i) dis[i] = inf * 1.0;
    memset(pre, -1, sizeof(pre));
    memset(vis, false, sizeof(vis));
    dis[s] = 0.0;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].vol > 0 && dis[v] > dis[u] + edge[i].c + eps) {
                dis[v] = dis[u] + edge[i].c;
                pre[v] = u;
                path[v] = i;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return pre[t] != -1;
}

double min_cost_max_flow(int s, int t) {
    double c = 0.0;
    int max_flow = 0;
    int i;
    while (spfa(s, t)) {
        int f = inf;
        for (int u = t; u != s; u = pre[u]) f = min(f, edge[path[u]].vol);
        for (int u = t; u != s; u = pre[u]) {
            i = path[u];
            edge[i].vol -= f;
            edge[i ^ 1].vol += f;
        }
        max_flow += f;
        c += (double)f * dis[t];
    }
    return c;
}

void init() {
    tot = -1;
    S = 0, T = n + 1;
    memset(head, -1, sizeof(head));
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i], &b[i]);
            c[i] = a[i] - b[i];
        }
        while (m--) {
            scanf("%d %d %d %lf", &u, &v, &cap, &p);
            p = -log2(1.0 - p);
            if (cap > 0) add_edge(u, v, 1, 0.0);
            if (cap > 1) add_edge(u, v, cap - 1, p);
        }
        for (int i = 1; i <= n; ++i) {
            if (c[i] > 0)
                add_edge(S, i, c[i], 0.0);
            else if (c[i] < 0)
                add_edge(i, T, -c[i], 0.0);
        }
        double ans = pow(2, -min_cost_max_flow(S, T));
        printf("%.2f\n", 1.0 - ans);
    }

    return 0;
}