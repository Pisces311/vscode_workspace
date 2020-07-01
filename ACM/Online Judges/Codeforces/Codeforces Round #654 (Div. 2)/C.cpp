#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t;
ll a, b, n, m;

bool solve() {
    if (a + b < n + m) return false;
    if (b < m) return false;
    b -= m;
    if (a + b < n) return false;
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
        cin >> a >> b >> n >> m;
        if (a < b) swap(a, b);
        if (solve())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}