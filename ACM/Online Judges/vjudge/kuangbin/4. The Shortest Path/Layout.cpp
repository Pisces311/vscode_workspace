#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1000 + 5;
const int maxm = 3e4 + 5;

struct Edge {
    int u, v, w, next;
} edge[maxm];

int N, ML, MD, tot, u, v, w;
bool vis[maxn];
int dis[maxn], cnt[maxn], head[maxn];

inline void init() {
    tot = -1;
    mem(head, -1);
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}

bool spfa() {
    queue<int> q;
    up(i, 1, N) dis[i] = INT_MAX;
    dis[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        vis[f] = false;
        link(i, f) {
            int v = edge[i].v, w = edge[i].w;
            if (dis[v] > dis[f] + w) {
                dis[v] = dis[f] + w;
                if (++cnt[v] > N) return true;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    init();
    scanf("%d %d %d", &N, &ML, &MD);
    up(i, 1, ML) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    up(i, 1, MD) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(v, u, -w);
    }
    if (spfa())
        printf("-1\n");
    else if (dis[N] == INT_MAX)
        printf("-2\n");
    else
        printf("%d\n", dis[N]);

    return 0;
}