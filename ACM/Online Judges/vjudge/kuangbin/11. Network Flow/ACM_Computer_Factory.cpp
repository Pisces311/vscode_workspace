#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 5e1 + 5;
const int maxp = 1e1 + 5;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int P, N;
int pfm[maxn], in[maxn][maxp], out[maxn][maxp];

struct Edge {
    int u, v, w, next, cap;
    bool reverse;
} edge[maxm];

// cur数组进行当前弧优化，记录之前访问到哪条边
int S, T, tot;
int head[maxn], depth[maxn], cur[maxn];

void init() {
    tot = -1;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w) {
    edge[++tot] = {u, v, w, head[u], w, false};
    head[u] = tot;
    edge[++tot] = {v, u, 0, head[v], w, true};
    head[v] = tot;
}

int dfs(int u, int flow) {
    if (u == T) return flow;
    for (int& i = cur[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if ((depth[v] == depth[u] + 1) && (edge[i].w != 0)) {
            int di = dfs(v, min(flow, edge[i].w));
            if (di > 0) {
                edge[i].w -= di;
                edge[i ^ 1].w += di;
                return di;
            }
        }
    }
    return 0;
}

bool bfs() {
    queue<int> q;
    memset(depth, 0, sizeof(depth));
    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = head[f]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if ((depth[v] == 0) && edge[i].w > 0) {
                depth[v] = depth[f] + 1;
                q.push(v);
            }
        }
    }
    if (depth[T] > 0) return true;
    return false;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        for (int i = S; i <= T; ++i) cur[i] = head[i];
        while (int d = dfs(S, inf)) ans += d;
    }
    return ans;
}

bool check(int x, int y) {
    for (int i = 1; i <= P; ++i) {
        if (in[y][i] == 1 && !out[x][i]) return false;
        if (!in[y][i] && out[x][i] == 1) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> P >> N) {
        init();
        for (int i = 1; i <= N; ++i) {
            cin >> pfm[i];
            for (int j = 1; j <= P; ++j) cin >> in[i][j];
            for (int j = 1; j <= P; ++j) cin >> out[i][j];
        }
        S = 0, T = 2 * N + 1;
        for (int i = 1; i <= N; ++i) {
            add_edge(i, i + N, pfm[i]);
        }
        for (int i = 1; i <= N; ++i) {
            bool connect_S = true, connect_T = true;
            for (int j = 1; j <= P; ++j) {
                if (in[i][j] == 1) connect_S = false;
                if (!out[i][j]) connect_T = false;
            }
            if (connect_S) add_edge(S, i, inf);
            if (connect_T) add_edge(i + N, T, inf);
            for (int j = 1; j <= N; ++j) {
                if (check(i, j)) add_edge(i + N, j, inf);
            }
        }
        cout << dinic() << ' ';
        vector<int> ans;
        for (int i = 0; i <= tot; ++i) {
            if (edge[i].reverse) continue;
            if (edge[i].w == edge[i].cap) continue;
            if (edge[i].u == S || edge[i].v == T) continue;
            if (edge[i].u + N == edge[i].v) continue;
            ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            int id = ans[i];
            cout << edge[id].u - N << ' ' << edge[id].v << ' '
                 << edge[id].cap - edge[id].w << '\n';
        }
    }

    return 0;
}