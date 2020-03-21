#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n;
int a[maxn], fa[maxn];
vector<int> g[maxn];
bool ok;

inline void init() {
    memset(fa, -1, sizeof(fa));
    for (int i = 1; i <= n; ++i) g[i].clear();
}

void bfs(int r) {
    queue<int> q;
    q.push(r);
    bool is_leaf = false;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (g[u].size() != 2 && !is_leaf)
            is_leaf = true;
        else if (g[u].size() && is_leaf)
            ok = false;
        for (int v : g[u]) {
            if (a[u] > a[v]) ok = false;
            q.push(v);
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
    int cas = 0;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            fa[v] = u;
        }
        ok = true;
        for (int i = 1; i <= n; ++i)
            if (g[i].size() > 2) ok = false;
        int r;
        for (int i = 1; i <= n; ++i)
            if (fa[i] == -1) {
                r = i;
                break;
            }
        bfs(r);
        cout << "Case #" << ++cas << ": ";
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}