#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr ll mod = 1e9 + 7;

int T, n;
int fa[maxn];
ll cnt2;
ll a[maxn], one[maxn], two[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int choose22(int u, int v) {
    return two[u] * two[v] % mod * (n - one[u] - one[v] - two[u] - two[v]) %
           mod;
}

int choose12(int u, int v) {
    return one[u] * two[v] % mod * (cnt2 - two[u] - two[v]) % mod;
}

void Union(int u, int v) {
    fa[u] = v;
    one[v] += one[u];
    two[v] += two[u];
}

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

// 处理模数为质数的情况
ll inv(ll x) { return qpow(x, mod - 2); }

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        memset(one, 0, sizeof(one));
        memset(two, 0, sizeof(two));
        cnt2 = 0;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            if (a[i] == 1)
                ++one[i];
            else {
                ++two[i];
                ++cnt2;
            }
        }
        ll ans = (cnt2 * (cnt2 - 1) % mod * (cnt2 - 2) % mod * inv(6) % mod +
                  (n - cnt2) * cnt2 % mod * (cnt2 - 1) % mod * inv(2) % mod) %
                 mod;
        cout << ans << '\n';
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            u = find(u), v = find(v);
            ans = (ans - choose22(u, v) - choose12(u, v) - choose12(v, u) +
                   3 * mod) %
                  mod;
            cout << ans << '\n';
            Union(u, v);
        }
    }

    return 0;
}