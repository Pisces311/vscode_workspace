#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int da, db;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> da >> db;
    if (da == db)
        cout << da << "1 " << db << "2\n";
    else if (da < db) {
        if (db - da == 1)
            cout << da << "9 " << db << "0\n";
        else
            cout << "-1\n";
    } else if (da > db) {
        if (da == 9 && db == 1)
            cout << da << "9 " << db << "00\n";
        else
            cout << "-1\n";
    }

    return 0;
}