#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int t, a, b, c, d;
int x, y, X1, Y1, X2, Y2;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> X1 >> Y1 >> X2 >> Y2;
        if (X1 == X2 && (a != 0 || b != 0))
            cout << "No\n";
        else if (Y1 == Y2 && (c != 0 || c != 0))
            cout << "No\n";
        else {
            if (a > b && x - (a - b) < X1)
                cout << "No\n";
            else if (b > a && x + (b - a) > X2)
                cout << "No\n";
            else if (c > d && y - (c - d) < Y1)
                cout << "No\n";
            else if (d > c && y + (d - c) > Y2)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }

    return 0;
}