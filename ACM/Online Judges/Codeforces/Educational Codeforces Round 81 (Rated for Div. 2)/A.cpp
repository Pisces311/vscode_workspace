#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int t, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        int num = n / 2;
        if (n & 1) {
            cout << '7';
            for (int i = 1; i < num; ++i) cout << '1';
            cout << '\n';
        } else {
            for (int i = 1; i <= num; ++i) cout << '1';
            cout << '\n';
        }
    }

    return 0;
}