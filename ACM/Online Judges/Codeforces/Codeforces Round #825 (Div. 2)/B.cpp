#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    b[0] = a[0];
    b[n] = a[n - 1];
    for (int i = 1; i < n; i++) b[i] = a[i - 1] * a[i] / gcd(a[i - 1], a[i]);
    for (int i = 0; i < n; i++)
        if (gcd(b[i], b[i + 1]) != a[i]) return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}