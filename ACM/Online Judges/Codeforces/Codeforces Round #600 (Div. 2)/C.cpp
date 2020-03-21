#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;

int m, n;
ll a[maxn], pre[maxn], ans[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < m; ++i) pre[i] = a[i];
    for (int i = m; i <= n; ++i) pre[i] = pre[i - m] + a[i];
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
        tot += pre[i];
        cout << tot << ' ';
    }
    cout << '\n';

    return 0;
}