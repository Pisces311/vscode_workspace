#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int T, n, m;
int g[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("6.in", "r", stdin);
    freopen("6.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            ++g[u][v];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) cout << g[i][j] << " \n"[j == n];
    }

    return 0;
}