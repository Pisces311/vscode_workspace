#include <limits.h>
#include <stdio.h>
#include <string.h>
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

const int maxn = 5e2 + 5;

struct node {
    int v, t;
};

int F, N, M, W, S, E, T;
vector<node> g[maxn];
bool vis[maxn];
int dis[maxn];
queue<int> q;

inline void init() {
    while (!q.empty()) q.pop();
    up(i, 1, N) dis[i] = INT_MAX;
    up(i, 1, N) g[i].clear();
    mem(vis, false);
}

bool spfa() {
    dis[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        vis[f] = false;
        up(i, 0, (int)g[f].size() - 1) {
            int v = g[f][i].v;
            if (dis[v] > dis[f] + g[f][i].t) {
                dis[v] = dis[f] + g[f][i].t;
                if (dis[1] < 0) return true;
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
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(F);
    while (F--) {
        scanf("%d %d %d", &N, &M, &W);
        init();
        up(i, 1, M) {
            scanf("%d %d %d", &S, &E, &T);
            g[S].push_back({E, T});
            g[E].push_back({S, T});
        }
        up(i, 1, W) {
            scanf("%d %d %d", &S, &E, &T);
            g[S].push_back({E, -T});
        }
        if (spfa())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}