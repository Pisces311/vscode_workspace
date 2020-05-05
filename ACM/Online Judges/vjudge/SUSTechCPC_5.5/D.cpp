#include <string.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int v, w, next;
} edge[maxn * 3];

int n, tot;
int a[maxn], b[maxn], dis[maxn], head[maxn];
bool vis[maxn];

inline void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v, int w) {
    edge[++tot] = {v, w, head[u]};
    head[u] = tot;
}

void spfa() {
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; ++i) add_edge(a[i], b[i] + 1, 2);
    int Max = *max_element(b + 1, b + n + 1) + 1;
    for (int i = 0; i <= Max; ++i) {
        add_edge(i + 1, i, -1);
        add_edge(i, i + 1, 0);
        dis[i] = -inf;
    }
    spfa();
    cout << dis[Max] << '\n';

    return 0;
}