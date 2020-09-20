#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, [](int a, int b) { return a > b; });
    int ans = 0;
    for (int i = 2; i < n; i += 2) swap(a[i], a[i + 1]), ++ans;
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];

    return 0;
}