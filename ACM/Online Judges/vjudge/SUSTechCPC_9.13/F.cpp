#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int T, n;
int a[maxn];

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
        int cur = 1;
        for (int i = 1; i <= n; i += 2) a[i] = cur++;
        for (int i = 2; i <= n; i += 2) a[i] = cur++;
        for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}