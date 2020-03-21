#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e6 + 5;

struct node {
    int v, dis, next;
    friend bool operator<(const node& a, const node& b) {
        return a.dis > b.dis;
    }
} g[maxn], rg[maxn];

int N, P, Q;
ll ans;
bool vis[maxn];
int dis[maxn];
priority_queue<node> pq;
int head[maxn], head2[maxn];

inline void init() {
    mem(head, 0);
    mem(head2, 0);
    ans = 0;
}

void dijkstra(node g[], int head[]) {
    mem(vis, false);
    up(i, 1, P) dis[i] = INT_MAX;
    pq.push({1, 0});
    dis[1] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        for (int i = head[t.v]; i; i = g[i].next)
            if (!vis[g[i].v]) {
                int v = g[i].v;
                if (dis[v] > t.dis + g[i].dis) {
                    dis[v] = t.dis + g[i].dis;
                    pq.push({v, dis[v]});
                }
            }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(N);
    while (N--) {
        scanf("%d %d", &P, &Q);
        init();
        int u, v, w;
        up(i, 1, Q) {
            scanf("%d %d %d", &u, &v, &w);
            g[i] = {v, w, head[u]};
            head[u] = i;
            rg[i] = {u, w, head2[v]};
            head2[v] = i;
        }
        dijkstra(g, head);
        up(i, 1, P) ans += dis[i];
        dijkstra(rg, head2);
        up(i, 1, P) ans += dis[i];
        printf("%lld\n", ans);
    }

    return 0;
}