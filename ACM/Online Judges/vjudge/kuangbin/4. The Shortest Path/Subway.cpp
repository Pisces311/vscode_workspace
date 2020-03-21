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

const int maxn = 2e2 + 5;
const double SP1 = 4e4;
const double SP2 = 1e4;

struct node {
    double x, y;
    int id;
} p[maxn];

struct Node {
    int v;
    double dis;
    friend bool operator<(const Node& a, const Node& b) {
        return a.dis > b.dis;
    }
};

int num;
double g[maxn][maxn];
double dis[maxn];
bool vis[maxn];
priority_queue<Node> pq;

int read() {
    double x, y;
    int k = 0, id = 3;
    while (~scanf("%lf %lf", &x, &y)) {
        ++id;
        if (x == -1 && y == -1) continue;
        p[k] = {x, y, id};
        ++k;
    }
    p[0].id = 0;
    p[1].id = 2;
    up(i, 0, k - 1) up(j, i, k - 1) {
        if (i == j)
            g[i][j] = 0;
        else if (p[i].id - p[j].id == -1)
            g[i][j] = g[j][i] =
                sqrt(pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2)) /
                SP1;
        else
            g[i][j] = g[j][i] =
                sqrt(pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2)) /
                SP2;
    }
    return k;
}

void dijkstra() {
    up(i, 0, num - 1) dis[i] = INT_MAX;
    pq.push({0, 0});
    dis[0] = 0;
    while (!pq.empty()) {
        Node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        up(i, 0, num - 1) if (!vis[i]) {
            if (dis[i] > t.dis + g[t.v][i]) {
                dis[i] = t.dis + g[t.v][i];
                pq.push({i, dis[i]});
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    num = read();
    dijkstra();
    printf("%d\n", (int)(60 * dis[1] + 0.5));

    return 0;
}