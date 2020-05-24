#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e6 + 5;

int n;
int a[maxn], b[maxn];

bool ok() {
    for (int i = 1; i < n; ++i)
        if (a[i] > a[i + 1]) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    sort(b + 1, b + n + 1);
    int l = 1, r = 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    for (int i = n; i >= 1; --i)
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    reverse(a + l, a + r + 1);
    if (ok()) {
        cout << l << ' ' << r << '\n';
    } else {
        cout << "impossible" << '\n';
    }

    return 0;
}