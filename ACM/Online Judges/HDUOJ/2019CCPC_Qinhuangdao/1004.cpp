#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        while (n % 2 == 0) n /= 2;
        while (n % 5 == 0) n /= 5;
        if (n == 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}