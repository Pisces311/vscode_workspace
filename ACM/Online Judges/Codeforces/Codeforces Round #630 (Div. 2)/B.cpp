#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e3 + 5;

int t, n;
int a[maxn], col[maxn];
bool used[12];
int m[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
map<int, int> Map;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        Map.clear();
        memset(used, false, sizeof(used));
        memset(col, -1, sizeof(col));
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 0; i < 11; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[j] % m[i] == 0 && col[j] == -1) {
                    col[j] = i;
                    used[i] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 11; ++i) {
            if (used[i]) Map[i] = ++cnt;
        }
        cout << cnt << '\n';
        for (int i = 1; i <= n; ++i) cout << Map[col[i]] << ' ';
        cout << '\n';
    }

    return 0;
}