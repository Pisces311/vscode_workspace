#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 2e6 + 5;
constexpr int mod = 1e9 + 7;

int t, n;
ll F[maxn], G[maxn];

inline void init() {
    F[1] = F[2] = 0;
    G[1] = G[2] = 0;
    for (int i = 3; i <= 2e6; ++i) {
        G[i] = (F[i - 1] + 2 * F[i - 2]) % mod;
        F[i] = max(1 + G[i - 1] + 2 * G[i - 2], F[i - 1] + 2 * F[i - 2]) % mod;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << 4 * F[n] % mod << '\n';
    }

    return 0;
}
