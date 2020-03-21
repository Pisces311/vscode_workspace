#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, N, red, blue, edge;
int col[maxn], cnt_red[maxn], cnt_blue[maxn];
vector<int> g[maxn];

inline void init() {
    red = blue = edge = 0;
    for (int i = 1; i <= N; ++i) g[i].clear();
    memset(cnt_red, 0, sizeof(cnt_red));
    memset(cnt_blue, 0, sizeof(cnt_blue));
}

void dfs(int u, int fa) {
    cnt_red[u] += (col[u] == 1);
    cnt_blue[u] += (col[u] == 2);
    for (int v : g[u])
        if (v != fa) {
            dfs(v, u);
            cnt_red[u] += cnt_red[v];
            cnt_blue[u] += cnt_blue[v];
        }
    if (cnt_red[u] == red && !cnt_blue[u]) ++edge;
    if (cnt_blue[u] == blue && !cnt_red[u]) ++edge;
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
        cin >> N;
        init();
        for (int i = 1; i <= N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= N; ++i) {
            cin >> col[i];
            red += (col[i] == 1);
            blue += (col[i] == 2);
        }
        dfs(1, -1);
        cout << edge << '\n';
    }

    return 0;
}