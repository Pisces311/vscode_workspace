#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

struct Edge {
    int u, v, next;
} edge[maxn << 1];

int t, n, m, tot, u, v, cnt;
int head[maxn], col[maxn];

inline void init() {
    cnt = tot = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
        col[i] = 0;
    }
}

inline void add_edge(int u, int v) {
    edge[++tot] = {u, v, head[u]};
    head[u] = tot;
}

void dfs(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!col[v]) {
            col[v] = col[u] == 1 ? 2 : 1;
            dfs(v);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("sample.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; ++i) {
            cin >> u >> v;
            add_edge(u, v);
            add_edge(v, u);
        }
        col[1] = 1;
        dfs(1);
        for (int i = 1; i <= n; ++i) cnt += (col[i] == 1);
        if (cnt * 2 <= n) {
            cout << cnt << '\n';
            for (int i = 1; i <= n; ++i)
                if (col[i] == 1) cout << i << ' ';
        } else {
            cout << n - cnt << '\n';
            for (int i = 1; i <= n; ++i)
                if (col[i] == 2) cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}