#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int n;
int deg[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ++deg[u];
        ++deg[v];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += max(0, deg[i] - 2);
    cout << ans << '\n';

    return 0;
}