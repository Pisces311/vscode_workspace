#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;
constexpr int maxm = 1e4 + 5;
constexpr int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
} edge[maxm];

int T, N, M;
int in[maxn], pre[maxn], id[maxn], vis[maxn];

int zhuliu(int rt, int N, int M) {
    int ans = 0;
    while (true) {
        for (int i = 1; i <= N; ++i) in[i] = inf;
        for (int i = 1; i <= M; ++i) {
            int u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if (u == v)
                continue;
            else if (in[v] > w) {
                pre[v] = u;
                in[v] = w;
            }
        }
        for (int i = 1; i <= N; ++i)
            if (i != rt && in[i] == inf) return -1;
        int cnt = 0;
        memset(id, 0, sizeof(id));
        memset(vis, 0, sizeof(vis));
        in[rt] = 0;
        for (int i = 1; i <= N; ++i) {
            ans += in[i];
            int v = i;
            while (!id[v] && v != rt && vis[v] != i) {
                vis[v] = i;
                v = pre[v];
            }
            if (v != rt && !id[v]) {
                id[v] = ++cnt;
                for (int j = pre[v]; j != v; j = pre[j]) id[j] = cnt;
            }
        }
        if (!cnt) break;
        for (int i = 1; i <= N; ++i)
            if (!id[i]) id[i] = ++cnt;
        for (int i = 1; i <= M; ++i) {
            int x = edge[i].u, y = edge[i].v;
            edge[i].u = id[x];
            edge[i].v = id[y];
            if (id[x] != id[y]) edge[i].w -= in[y];
        }
        N = cnt;
        rt = id[rt];
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            w *= -1000;
            if (v == N) w -= (N - u);
            edge[i] = {u, v, w};
        }
        int ans = zhuliu(1, N, M);
        cout << -ans / 1000 << ' ' << N - (-ans) % 1000 << '\n';
    }

    return 0;
}