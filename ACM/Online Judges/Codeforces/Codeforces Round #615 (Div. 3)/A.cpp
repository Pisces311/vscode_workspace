#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, a, b, c, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> n;
        int d = max(max(a, b), c);
        n -= d - a;
        n -= d - b;
        n -= d - c;
        if (n < 0 || n % 3 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}