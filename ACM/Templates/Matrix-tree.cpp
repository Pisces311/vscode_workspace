#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;
constexpr int mod = 998244353;

struct Edge {
    int u, v, w;
};

int t, N, m;
int g[maxn][maxn];
vector<Edge> edge;

ll qpow(ll g, ll b) {
    ll ret = 1;
    g %= mod;
    while (b > 0) {
        if (b & 1) ret = (ret * g) % mod;
        b /= 2;
        g = (g * g) % mod;
    }
    return ret;
}

ll inv(ll x) { return qpow(x, mod - 2); }

int det(int n) {
    int rt = 1;
    for (int i = 1; i <= n; ++i) {
        int j = -1;
        for (int k = i; k <= n; ++k)
            if (g[k][i] != 0) {
                j = k;
                break;
            }
        if (j == -1) return 0;
        if (i != j) {
            for (int k = i; k <= n; ++k) {
                swap(g[i][k], g[j][k]);
                rt = (mod - rt) % mod;
            }
        }
        for (j = i + 1; j <= n; j++) {
            if (g[j][i] == 0) continue;
            int r = 1ll * g[j][i] * inv(g[i][i]) % mod;
            for (int k = i; k <= n; ++k) {
                g[j][k] -= 1ll * g[i][k] * r % mod;
                if (g[j][k] < 0) g[j][k] += mod;
            }
        }
    }
    for (int i = 1; i <= n; ++i) rt = 1ll * rt * g[i][i] % mod;
    return rt;
}

// 返回图中不同生成树的个数
int solve(int bit) {
    memset(g, 0, sizeof(g));
    for (Edge e : edge) {
        if (bit == -1 || e.w & (1 << bit)) {
            g[e.u][e.u]++;
            g[e.v][e.v]++;
            g[e.u][e.v]--;
            g[e.v][e.u]--;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) g[i][j] = (g[i][j] + mod) % mod;
    }
    return det(N - 1);
}