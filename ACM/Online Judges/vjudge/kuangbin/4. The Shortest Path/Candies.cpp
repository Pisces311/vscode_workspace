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

const int maxn = 3e4 + 5;
const int maxm = 1.5e5 + 5;

struct node {
    int v, dis, next;
    friend bool operator<(const node& a, const node& b) {
        return a.dis > b.dis;
    }
} g[maxm];

int N, M;
bool vis[maxn];
int dis[maxn], head[maxn];
priority_queue<node> pq;

inline void init() {
    up(i, 1, N) dis[i] = INT_MAX;
    mem(head, 0);
}

void dijkstra() {
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
                if (dis[v] > dis[t.v] + g[i].dis) {
                    dis[v] = dis[t.v] + g[i].dis;
                    pq.push({v, dis[v]});
                }
            }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d", &N, &M);
    init();
    int u, v, w;
    up(i, 1, M) {
        scanf("%d %d %d", &u, &v, &w);
        g[i] = {v, w, head[u]};
        head[u] = i;
    }
    dijkstra();
    print(dis[N]);

    return 0;
}