#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 5;

int N;
int son[maxn], Max[maxn];
vector<int> g[maxn], ans;

int dfs(int u, int pre) {
    son[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == pre) continue;
        int res = dfs(v, u);
        son[u] += res;
        Max[u] = max(Max[u], res);
    }
    return son[u];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    for (int i = 1; i <= N - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= N; ++i) {
        if (Max[i] <= N / 2 && N - son[i] <= N / 2) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);

    return 0;
}