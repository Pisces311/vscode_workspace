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
    friend bool operator<(const node& a, const node& b) {
        return a.dis > b.dis;
    }
};

int N, A, B;
vector<node> g[maxn];
int dis[maxn];
bool vis[maxn];
priority_queue<node> pq;

void dijkstra(int s) {
    up(i, 1, N) dis[i] = INT_MAX;
    pq.push({s, 0});
    dis[s] = 0;
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

    scanf("%d %d %d", &N, &A, &B);
    int x, y;
    up(i, 1, N) {
        scan(x);
        int tmp = x;
        while (tmp--) {
            scan(y);
            g[i].push_back({y, (tmp + 1 != x)});
        }
    }
    dijkstra(A);
    if (dis[B] == INT_MAX)
        print(-1);
    else
        print(dis[B]);

    return 0;
}