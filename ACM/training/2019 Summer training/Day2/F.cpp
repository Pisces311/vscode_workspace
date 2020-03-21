#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

int t, N, M, p, s, e;

namespace dinic {
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;
const int maxn = 1000100, maxm = 2000020;
struct edge {
    int to, next, w;
} e[maxm];
int q[maxn], dis[maxn], head[maxn], cur[maxn], cnt = 1, S, T;
void init() {
    clr(head);
    clr(cur);
    cnt = 1;
}
void insert(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].next = head[u];
    e[cnt].w = w;
    head[u] = cnt;
    e[++cnt].to = u;
    e[cnt].next = head[v];
    e[cnt].w = 0;
    head[v] = cnt;
}
bool bfs() {
    clr(dis);
    dis[S] = 1;
    int h = 0, t = 0;
    q[t++] = S;
    while (h < t) {
        int u = q[h++];
        for (int i = head[u]; i; i = e[i].next)
            if (!dis[e[i].to] && e[i].w > 0)
                dis[e[i].to] = dis[u] + 1, q[t++] = e[i].to;
    }
    return (dis[T] > 0);
}
int dfs(int u, int res) {
    if (u == T || res == 0) return res;
    int ret = 0;
    for (int i = cur[u]; i; i = e[i].next)
        if (dis[e[i].to] == dis[u] + 1 && e[i].w > 0) {
            int v = e[i].to, flow = dfs(v, min(res - ret, e[i].w));
            e[i].w -= flow;
            e[i ^ 1].w += flow;
            ret += flow;
            if (e[i].w > 0) cur[u] = i;
            if (ret == res) break;
        }
    if (ret == 0) dis[u] = 0;
    return ret;
}
int dinic() {
    int ret = 0;
    while (bfs()) {
        for (int i = S; i <= T; i++) cur[i] = head[i];
        ret += dfs(S, 1 << 30);
    }
    return ret;
}
}  // namespace dinic

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    up(case_num, 1, t) {
        printf("Case %d: ", case_num);
        scanf("%d %d", &N, &M);
        dinic::init();
        int ma = 0;
        dinic::S = 0;
        int sum = 0;
        up(i, 1, N) {
            scanf("%d %d %d", &p, &s, &e);
            sum += p;
            ma = max(ma, e);
            dinic::insert(dinic::S, i, p);
            up(j, s, e) dinic::insert(i, j + N, 1);
        }
        dinic::T = N + ma + 1;
        up(i, 1, ma) dinic::insert(i + N, dinic::T, M);
        if (dinic::dinic() == sum)
            printf("Yes\n\n");
        else
            printf("No\n\n");
    }

    return 0;
}