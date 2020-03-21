#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e4 + 5;

int T, n, m;
int ans[maxn], out[maxn];
vector<int> g[maxn];

inline void init() {
    memset(out, 0, sizeof(out));
    for (int i = 1; i <= n; ++i) g[i].clear();
}

void toposort() {
    priority_queue<int> pq;
    int cnt = n;
    for (int i = 1; i <= n; ++i)
        if (!out[i]) pq.push(i);
    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        ans[cnt--] = v;
        for (int u : g[v]) {
            --out[u];
            if (!out[u]) pq.push(u);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("6.in", "r", stdin);
    freopen("6.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[v].push_back(u);
            ++out[u];
        }
        toposort();
        for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
    }

    return 0;
}