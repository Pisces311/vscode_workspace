#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, N;
int depth[maxn];
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= N; ++i) g[i].clear();
}

void dfs(int u, int fa, int d) {
    depth[u] = d;
    for (int v : g[u])
        if (v != fa) dfs(v, u, d + 1);
}

int main() {
#ifdef DEBUG
    freopen("SUSTech/CS203/2020Spring/Quiz 2/A/Input/3.in", "r", stdin);
    freopen("SUSTech/CS203/2020Spring/Quiz 2/A/Output/3.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        init();
        for (int i = 1; i <= N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, -1, 0);
        for (int i = 1; i <= N; ++i) cout << depth[i] << ' ';
        cout << '\n';
    }

    return 0;
}