#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, d;

bool solve() {
    for (int i = 0; i <= 1e6; ++i) {
        if (i + ceil(1.0 * d / (i + 1)) <= n) return true;
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> d;
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}