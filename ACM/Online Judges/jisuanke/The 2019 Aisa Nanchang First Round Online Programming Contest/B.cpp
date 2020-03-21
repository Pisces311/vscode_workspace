#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int v, w;
    bool operator<(const node& a) const { return w > a.w; }
};

int T, V, E, S, K, C;
int dis1[maxn], dis2[maxn], ks[maxn];
vector<node> g[maxn];

inline void init() {
    for (int i = 1; i <= V; ++i) {
        dis1[i] = dis2[i] = inf;
        g[i].clear();
    }
}

void dijkstra1(int s) {
    priority_queue<node> pq;
    pq.push({s, 0});
    dis1[s] = 0;
    while (!pq.empty()) {
        node u = pq.top();
        pq.pop();
        for (node i : g[u.v]) {
            int v = i.v;
            if (dis1[v] > dis1[u.v] + i.w) {
                dis1[v] = dis1[u.v] + i.w;
                pq.push({v, dis1[v]});
            }
        }
    }
}

void dijkstra2() {
    priority_queue<node> pq;
    for (int i = 1; i <= K; ++i) {
        pq.push({ks[i], 0});
        dis2[ks[i]] = 0;
    }
    while (!pq.empty()) {
        node u = pq.top();
        pq.pop();
        for (node i : g[u.v]) {
            int v = i.v;
            if (dis2[v] > dis2[u.v] + i.w) {
                dis2[v] = dis2[u.v] + i.w;
                pq.push({v, dis2[v]});
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

    cin >> T;
    while (T--) {
        cin >> V >> E >> S >> K >> C;
        init();
        for (int i = 1; i <= K; ++i) cin >> ks[i];
        for (int i = 1; i <= E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dijkstra1(S);
        dijkstra2();
        int hero = *max_element(dis1 + 1, dis1 + V + 1);
        int team = *max_element(dis2 + 1, dis2 + V + 1);
        if (1.0 * hero / C <= team)
            cout << hero << '\n';
        else
            cout << team << '\n';
    }

    return 0;
}