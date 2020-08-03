#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e5 + 5;

int T, N, n;
int a[maxn], b[maxn];
bool vis[maxn], loop;
map<int, int> ma;
vector<int> g[maxn];

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(vis + 1, false, sizeof(bool) * n);
}

int discrete() {
    ma.clear();
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        if (ma.find(a[i]) == ma.end()) ma[a[i]] = ++cnt;
    for (int i = 1; i <= N; ++i)
        if (ma.find(b[i]) == ma.end()) ma[b[i]] = ++cnt;
    for (int i = 1; i <= N; ++i) a[i] = ma[a[i]];
    for (int i = 1; i <= N; ++i) b[i] = ma[b[i]];
    return cnt;
}

void dfs(int u, int fa) {
    int tofa = 0;
    vis[u] = true;
    for (int v : g[u]) {
        if (v == fa) {
            ++tofa;
            if (tofa == 2) loop = true;
        } else if (vis[v])
            loop = true;
        else
            dfs(v, u);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    int cas = 0;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> a[i] >> b[i];
        n = discrete();
        init();
        for (int i = 1; i <= N; ++i) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
        int cut = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) {
                loop = false;
                dfs(i, -1);
                if (!loop) ++cut;
            }
        cout << "Case #" << ++cas << ": " << n - cut << '\n';
    }

    return 0;
}