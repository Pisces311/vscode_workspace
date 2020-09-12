#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e3 + 5;

int T, n, k;
int a[maxn];
vector<int> g[maxn];

int prime[2000005], pnum = 0;
bool nprime[2000005];

bool vis[maxn];
int match[maxn];

int dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[u] = v;
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int sum = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; ++i) {
        if (match[i] == -1) {
            memset(vis, false, sizeof(vis));
            sum += dfs(i);
        }
    }
    return sum;
}

void euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!nprime[i]) prime[++pnum] = i;
        for (int j = 1; j <= pnum; ++j) {
            if (i * prime[j] > n) break;
            nprime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

inline void init() {
    for (int i = 1; i <= n; ++i) g[i].clear();
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    euler_sieve(2e6);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        init();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!nprime[a[i] + a[j]]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (g[i].empty()) ++cnt;
        int m = hungary();
        if (k <= m)
            cout << 2 * k << '\n';
        else
            cout << 2 * m + min(k - m, n - cnt - 2 * m) << '\n';
    }

    return 0;
}