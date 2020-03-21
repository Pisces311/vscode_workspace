#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int x, y;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    if (y == 0 || x < y - 1 || (y == 1 && x > 0)) {
        cout << "No\n";
        return 0;
    }
    y -= 1;
    x -= y;
    if (x & 1)
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}