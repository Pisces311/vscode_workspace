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

const int maxn = 1e5 + 5;

struct node {
    int v, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int T, N, M, C, u, v, w, layer;
vector<node> g[3 * maxn];
vector<int> lay[maxn];
bool vis[3 * maxn];
int dis[3 * maxn];
priority_queue<node> pq;

void dijkstra() {
    mem(dis, 0x3f3f3f3f);
    mem(vis, false);
    pq.push({1, 0});
    dis[1] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        up(i, 0, (int)g[t.v].size() - 1) if (!vis[g[t.v][i].v]) {
            int v = g[t.v][i].v;
            if (dis[v] > dis[t.v] + g[t.v][i].dis) {
                dis[v] = dis[t.v] + g[t.v][i].dis;
                pq.push({v, dis[v]});
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(T);
    up(k, 1, T) {
        scanf("%d %d %d", &N, &M, &C);
        up(i, 1, N) lay[i].clear();
        up(i, 1, N) {
            scan(layer);
            lay[layer].push_back(i);
        }
        up(i, 1, 3 * N) g[i].clear();
        up(i, 1, M) {
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        int node = N + 1;
        up(i, 1, N - 1) if (!lay[i].empty() && !lay[i + 1].empty()) {
            up(j, 0, (int)lay[i].size() - 1) {
                u = lay[i][j];
                g[u].push_back({node, C});
            }
            up(j, 0, (int)lay[i + 1].size() - 1) {
                v = lay[i + 1][j];
                g[node].push_back({v, 0});
            }
            node++;
        }
        dn(i, N, 2) if (!lay[i].empty() && !lay[i - 1].empty()) {
            up(j, 0, (int)lay[i].size() - 1) {
                u = lay[i][j];
                g[u].push_back({node, C});
            }
            up(j, 0, (int)lay[i - 1].size() - 1) {
                v = lay[i - 1][j];
                g[node].push_back({v, 0});
            }
            node++;
        }
        dijkstra();
        if (dis[N] != 0x3f3f3f3f)
            printf("Case #%d: %d\n", k, dis[N]);
        else
            printf("Case #%d: -1\n", k);
    }

    return 0;
}