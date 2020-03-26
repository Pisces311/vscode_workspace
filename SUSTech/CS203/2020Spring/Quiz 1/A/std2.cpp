#include <string.h>

#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int T, n;
int a[maxn];
bool vis[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        memset(vis, false, sizeof(vis));
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            if (!vis[a[i]]) {
                cout << a[i] << '\n';
                vis[a[i]] = true;
            }
        }
    }

    return 0;
}