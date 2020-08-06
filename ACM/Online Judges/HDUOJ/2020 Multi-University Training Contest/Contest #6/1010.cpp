#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e2 + 5;
constexpr int mod = 998244353;

struct Edge {
    int u, v, w;
};

int t, N, m;
int a[maxn][maxn];
vector<Edge> edge;

ll qpow(ll a, ll b) {
    ll ret = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ret;
}

ll inv(ll x) { return qpow(x, mod - 2); }

int det(int n) {
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        int j = -1, k;
        for (k = i; k <= n; k++)
            if (a[k][i] != 0) {
                j = k;
                break;
            }
        if (j == -1) return 0;
        if (i != j) {
            for (k = i; k <= n; k++) {
                swap(a[i][k], a[j][k]);
                rt = (mod - rt) % mod;
            }
        }
        for (j = i + 1; j <= n; j++) {
            if (a[j][i] == 0) continue;
            int r = 1LL * a[j][i] * inv(a[i][i]) % mod;
            for (k = i; k <= n; k++) {
                a[j][k] -= 1LL * a[i][k] * r % mod;
                if (a[j][k] < 0) a[j][k] += mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) rt = 1LL * rt * a[i][i] % mod;
    return rt;
}

int solve(int bit) {
    memset(a, 0, sizeof(a));
    for (Edge e : edge) {
        if (bit == -1 || e.w & (1 << bit)) {
            a[e.u][e.u]++;
            a[e.v][e.v]++;
            a[e.u][e.v]--;
            a[e.v][e.u]--;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) a[i][j] = (a[i][j] + mod) % mod;
    }
    return det(N - 1);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> N >> m;
        edge.clear();
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back({u, v, w});
        }
        ll sum = 0, cnt = 0;
        cnt = solve(-1);
        for (int i = 0; i < 30; ++i) {
            int num = solve(i);
            sum += 1ll * num * (1 << i) % mod;
            sum %= mod;
        }
        cout << sum * inv(cnt) % mod << '\n';
    }

    return 0;
}