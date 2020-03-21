#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1.5e5 + 5;

int T, n;
int fa[maxn];
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
        if (g[u][0] == 0 && g[u][1]) ok = false;
        if ((g[u][0] == 0 || g[u][1] == 0) && !is_leaf)
            is_leaf = true;
        else if ((g[u][0] || g[u][1]) && is_leaf)
            ok = false;
        for (int v : g[u])
            if (v) q.push(v);
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
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            g[i].push_back(x);
            fa[x] = i;
            g[i].push_back(y);
            fa[y] = i;
        }
        ok = true;
        int r;
        for (int i = 1; i <= n; ++i)
            if (fa[i] == -1) r = i;
        bfs(r);
        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}