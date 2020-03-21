#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct lst {
    int u, w;
    bool operator<(const lst& rhs) const { return w < rhs.w; }
};

int n, k;
int son[maxn];
vector<int> g[maxn], ls[maxn];

void dfs(int u) {
    if (g[u].empty()) {
        son[u] = 1;
        return;
    }
    int ma = 0, id = 0;
    for (int v : g[u]) {
        dfs(v);
        if (son[v] > ma) {
            ma = son[v];
            id = v;
        }
    }
    son[u] = ma + 1;
    for (int v : g[u])
        if (v != id) ls[u].push_back(v);
    for (int v : ls[id]) ls[u].push_back(v);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 2, fa; i <= n; ++i) {
        cin >> fa;
        g[fa].push_back(i);
    }
    dfs(1);
    priority_queue<lst> pq;
    pq.push({1, son[1]});
    int ans = 0;
    while (!pq.empty()) {
        lst t = pq.top();
        pq.pop();
        int u = t.u, w = t.w;
        ans += w;
        --k;
        if (!k) break;
        for (int v : ls[u]) pq.push({v, son[v]});
    }
    cout << ans << '\n';

    return 0;
}