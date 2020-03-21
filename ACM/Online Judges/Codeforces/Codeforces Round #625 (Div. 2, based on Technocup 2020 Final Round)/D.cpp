#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

struct node {
    int id, d;
};

int n, m, k;
vector<int> pre[maxn], suc[maxn];
int dis[maxn], path[maxn];
queue<node> q;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        pre[v].push_back(u);
        suc[u].push_back(v);
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) cin >> path[i];
    int s = path[1], t = path[k];
    q.push({t, 0});
    memset(dis, -1, sizeof(dis));
    dis[t] = 0;
    while (!q.empty()) {
        node v = q.front();
        q.pop();
        for (int u : pre[v.id]) {
            if (dis[u] == -1) {
                dis[u] = v.d + 1;
                q.push({u, dis[u]});
            }
        }
    }
    int _min = 0, _max = 0;
    for (int i = 1; i < k; ++i) {
        int min_dis = 0x3f3f3f3f;
        int num = 0;
        for (int j : suc[path[i]]) min_dis = min(min_dis, dis[j]);
        for (int j : suc[path[i]])
            if (dis[j] == min_dis) ++num;
        if (dis[path[i + 1]] > min_dis)
            ++_min, ++_max;
        else if (dis[path[i + 1]] == min_dis && num > 1)
            ++_max;
    }
    cout << _min << ' ' << _max << '\n';

    return 0;
}