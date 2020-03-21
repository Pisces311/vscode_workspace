#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
ll k;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> k;
        cout << ((k * (k + 1) * (2 * k + 1) / 6) + (k * (k + 1) / 2)) / 2
             << '\n';
    }

    return 0;
}