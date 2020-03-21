#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <string>
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

int n;
int g[maxn][maxn];
bool vis[maxn];
int dis[maxn];
priority_queue<node> pq;

inline void init() { up(i, 1, n) dis[i] = INT_MAX; }

void dijkstra() {
    pq.push({1, 0});
    dis[1] = 0;
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (vis[t.v]) continue;
        vis[t.v] = true;
        up(i, 1, n) if (!vis[i] && g[t.v][i] != -1) {
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

    scan(n);
    char s[10];
    up(i, 2, n) up(j, 1, i - 1) {
        init();
        scanf("%s", &s[0]);
        if (s[0] != 'x')
            g[i][j] = g[j][i] = atoi(s);
        else
            g[i][j] = g[j][i] = -1;
    }
    dijkstra();
    print(*max_element(dis + 1, dis + n + 1));

    return 0;
}