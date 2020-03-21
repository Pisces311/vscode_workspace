#include <limits.h>
#include <math.h>
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

const int maxn = 1e2 + 5;

struct node {
    int v, dis;
    node(int v, int dis) : v(v), dis(dis) {}
    friend bool operator<(const node& a, const node& b) {
        return a.dis > b.dis;
    }
};

int n, m;
int dis[maxn], rate[maxn];
int g[maxn][maxn];
bool vis[maxn];
priority_queue<node> q;

void dijkstra(int l, int h) {
    up(i, 1, n) dis[i] = INT_MAX;
    mem(vis, false);
    dis[0] = 0;
    q.push(node(0, 0));
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        up(i, 1, n) if (!vis[i] && g[t.v][i] != -1 && l <= rate[i] &&
                        rate[i] <= h && dis[i] > dis[t.v] + g[t.v][i]) {
            dis[i] = dis[t.v] + g[t.v][i];
            q.push(node(i, dis[i]));
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scanf("%d %d", &m, &n);
    int p, l, x, t, v;
    mem(g, -1);
    up(i, 1, n) {
        scanf("%d %d %d", &p, &l, &x);
        rate[i] = l;
        g[0][i] = p;
        while (x--) {
            scanf("%d %d", &t, &v);
            g[t][i] = v;
        }
    }
    int ans = INT_MAX;
    up(i, rate[1] - m, rate[1]) {
        dijkstra(i, i + m);
        ans = min(ans, dis[1]);
    }
    print(ans);

    return 0;
}