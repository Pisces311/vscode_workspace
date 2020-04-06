#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, n, x;
int a[maxn];
bool vis[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        memset(vis, false, sizeof(vis));
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) vis[a[i]] = true;
        int ans = -1;
        for (int i = 1; i <= 205; ++i) {
            if (vis[i])
                continue;
            else if (!vis[i] && x)
                --x;
            else {
                ans = i;
                break;
            }
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}