#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, a, b, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> a >> b >> n;
        n %= 3;
        if (n == 2)
            cout << (a ^ b) << '\n';
        else if (n == 1)
            cout << b << '\n';
        else
            cout << a << '\n';
    }

    return 0;
}