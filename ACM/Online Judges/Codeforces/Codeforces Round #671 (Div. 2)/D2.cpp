#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n;
int a[maxn], ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1;
    for (int i = 2; i <= n; i += 2) ans[i] = a[j++];
    for (int i = 1; i <= n; i += 2) ans[i] = a[j++];
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) cnt++;
    cout << cnt << '\n';
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];

    return 0;
}