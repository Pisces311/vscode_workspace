#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;
constexpr ll mod = 1e9 + 7;

int n, c, j;
ll S[2][maxn];

ll str2(int i, int j) {
    if (!i) return S[i][j];
    int p = i & 1, q = p ^ 1;
    S[p][0] = 0;
    for (int k = 1; k <= j; ++k)
        S[p][k] = (S[q][k - 1] + k * S[q][k] % mod) % mod;
    return S[p][j];
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c >> j;
    S[0][0] = 1;
    for (int i = 1; i <= j; ++i) S[0][i] = 0;
    ll ans = 0, mul = 1;
    for (int i = 0; i <= n; ++i) {
        ans += mul * str2(i, j) % mod;
        ans %= mod;
        mul = (mul * c) % mod;
    }
    cout << ans << '\n';

    return 0;
}