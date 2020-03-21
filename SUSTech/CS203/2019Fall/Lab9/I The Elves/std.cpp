#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int T, n, m;
vector<int> e[maxn];
ll a[maxn], b[maxn], d[maxn];
ll ans[maxn];

inline void init() {
    for (int i = 0; i <= n; ++i) e[i].clear();
    memset(d, 0, sizeof(d));
    memset(ans, 0, sizeof(ans));
}

void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            ans[v] = (ans[v] + (ans[u] + b[u]) % mod) % mod;
            if (--d[v] == 0) q.push(v);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            e[v].push_back(u);
            d[u]++;
        }
        topo();
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res = (res + 1ll * ans[i] * a[i] % mod) % mod;
        cout << res << '\n';
    }

    return 0;
}