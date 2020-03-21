#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int N, M;
char g[105][105];
vector<pii> Home, man;

struct edge {
    int v, w, cost, next;
} edge[maxm];

int S, T, tot;
int head[maxn], dis[maxn], pre[maxn];
bool vis[maxn];

void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
    Home.clear();
    man.clear();
}

void add_edge(int u, int v, int w, int cost) {
    edge[++tot] = {v, w, cost, head[u]};
    head[u] = tot;
    edge[++tot] = {u, 0, -cost, head[v]};
    head[v] = tot;
}

bool spfa() {
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    dis[S] = 0;
    queue<int> q;
    q.push(S);
    vis[S] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (edge[i].w) {
                int v = edge[i].v;
                if (dis[u] + edge[i].cost < dis[v]) {
                    dis[v] = dis[u] + edge[i].cost;
                    pre[v] = i;
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    return pre[T] != -1;
}

int min_cost_max_flow() {
    int ret = 0;
    while (spfa()) {
        int flow = inf;
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v)
            flow = min(edge[pre[i]].w, flow);
        for (int i = T; i != S; i = edge[pre[i] ^ 1].v) {
            edge[pre[i]].w -= flow;
            edge[pre[i] ^ 1].w += flow;
            ret += edge[pre[i]].cost * flow;
        }
    }
    return ret;
}

int get_dis(int i, int j) {
    return abs(man[i].first - Home[j].first) +
           abs(man[i].second - Home[j].second);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N >> M, N + M) {
        init();
        for (int i = 1; i <= N; ++i) cin >> (g[i] + 1);
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (g[i][j] == 'H')
                    Home.push_back(make_pair(i, j));
                else if (g[i][j] == 'm')
                    man.push_back(make_pair(i, j));
        int sz = man.size();
        S = 0, T = 2 * sz + 1;
        for (int i = 0; i < sz; ++i) {
            int id = i + 1;
            add_edge(S, id, 1, 0);
        }
        for (int i = 0; i < sz; ++i) {
            int id = sz + i + 1;
            add_edge(id, T, 1, 0);
        }
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                int u = i + 1, v = sz + j + 1;
                add_edge(u, v, 1, get_dis(i, j));
            }
        }
        cout << min_cost_max_flow() << '\n';
    }

    return 0;
}