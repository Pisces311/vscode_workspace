#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e2 + 5;

int N, K;
int a[maxn], dp[maxn][maxn];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= N; ++i) g[i].clear();
}

void dfs(int u, int pre) {
    dp[u][1] = a[u];
    for (int v : g[u]) {
        dfs(v, u);
        for (int i = 2; i <= K; ++i) {
            dp[u][i] = max(dp[u][i], dp[v][i - 1] + a[u]);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &N, &K)) {
        init();
        for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= N - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            ++u, ++v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, -1);
    }

    return 0;
}