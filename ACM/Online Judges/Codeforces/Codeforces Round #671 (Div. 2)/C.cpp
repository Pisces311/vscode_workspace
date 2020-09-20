#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, n, x;
int a[maxn];

bool equal() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != x) return false;
    return true;
}

int solve() {
    if (equal()) return 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] == x) return 1;
    if (accumulate(a + 1, a + n + 1, 0) == n * x)
        return 1;
    else
        return 2;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cout << solve() << '\n';
    }

    return 0;
}