#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

struct node {
    int a, b;
} a[maxn];

int n;
int pos[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].a;
    for (int i = 1; i <= n; ++i) cin >> a[i].b;
    sort(a + 1, a + n + 1, [](node x, node y) { return x.b < y.b; });
    for (int i = 1; i <= n; ++i) a[i].b = i;
    sort(a + 1, a + n + 1, [](node x, node y) { return x.a < y.a; });
    for (int i = 1; i <= n; ++i) pos[a[i].b] = i;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].b != n - i + 1) {
            pos[a[i].b] = pos[n - i + 1];
            swap(a[i].b, a[pos[n - i + 1]].b);
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}