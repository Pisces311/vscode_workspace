#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

int t, n;
int a[maxn];

bool solve(int p) {
    if (p == n)
        return false;
    else if (a[n] < a[1])
        return false;
    return true;
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
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int p = min_element(a + 1, a + n + 1) - a;
        if (solve(p))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}