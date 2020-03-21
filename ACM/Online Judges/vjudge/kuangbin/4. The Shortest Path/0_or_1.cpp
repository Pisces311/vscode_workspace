#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 3e2 + 5;

struct node {
    int v, dis;
    bool operator<(const node& a) const { return dis > a.dis; }
};

int n;
int C[maxn][maxn], dis[maxn];

void dijkstra(int s) {
    priority_queue<node> pq;
    up(i, 1, n) dis[i] = INT_MAX;
    pq.push({s, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        up(i, 1, n) if (i != t.v) {
            int v = i;
            if (dis[v] > t.dis + C[t.v][i]) {
                dis[v] = t.dis + C[t.v][i];
                pq.push({v, dis[v]});
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d", &n)) {
        up(i, 1, n) up(j, 1, n) scanf("%d", &C[i][j]);
        dijkstra(1);
        int s1 = dis[1], s2 = dis[n];
        dijkstra(n);
        s1 += dis[n];
        printf("%d\n", min(s1, s2));
    }

    return 0;
}