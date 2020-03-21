#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int u, w;
};

int T, n, k, S, ans;
bool vis[maxn], is[maxn];
vector<int> g[maxn];
queue<node> q;

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(is, false, sizeof(is));
}

void dfs(int u, int fa, int w) {
    for (int v : g[u]) {
        if (v != fa) {
            if (is[v] && w + 1 > ans) {
                ans = w + 1;
                S = v;
            }
            dfs(v, u, w + 1);
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
        cin >> n >> k;
        init();
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int fir = -1;
        for (int i = 1; i <= k; ++i) {
            int id;
            cin >> id;
            if (fir == -1) fir = id;
            is[id] = true;
        }
        ans = 0;
        dfs(fir, -1, 0);
        ans = 0;
        dfs(S, -1, 0);
        cout << ((ans + 1) >> 1) << '\n';
    }

    return 0;
}