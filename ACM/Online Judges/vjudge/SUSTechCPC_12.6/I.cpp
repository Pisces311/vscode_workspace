#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int N, M;
int dis[maxn];
set<int> g[maxn], res;

void bfs(int S) {
    memset(dis + 1, -1, sizeof(int) * N);
    queue<int> q;
    q.push(S);
    dis[S] = 0;
    res.erase(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i = res.begin(); i != res.end();) {
            int v = *i;
            if (g[u].find(v) == g[u].end()) {
                q.push(v);
                dis[v] = dis[u] + 1;
                i = res.erase(i);
            } else
                ++i;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        res.clear();
        for (int i = 1; i <= N; ++i) res.insert(i);
        for (int i = 1; i <= N; ++i) g[i].clear();
        int u, v;
        for (int i = 0; i < M; ++i) {
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
        }
        int S;
        cin >> S;
        bfs(S);
        for (int i = 1; i <= N; ++i)
            if (i != S) cout << dis[i] << " \n"[i == N];
    }

    return 0;
}